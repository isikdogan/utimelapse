#include "processthread.h"
#include <QtCore>

ProcessThread::ProcessThread(QObject *parent) : QThread(parent)
{
}

void ProcessThread::setParameters(int resolutionIdx,
                                  QDir directory,
                                  QStringList listOfFiles,
                                  int frameRate,
                                  bool deflicker,
                                  int deflickerWindowSize,
                                  bool motionDenoiser,
                                  bool isGaussian,
                                  int bufferSize,
                                  bool reduceCameraShake,
                                  bool ignorePerspective,
                                  int cropSize, bool isFast, QString outputFilename)
{
    int resolutions[] = {240, 360, 480, 720, 1080, 2160, 4380};

    this->outputFilename = outputFilename;

    this->imgHeight = resolutions[resolutionIdx] * 100 / (100 - 2 * cropSize);

    this->listOfFiles = listOfFiles;

    this->directory = directory;

    this->deflicker = deflicker;

    this->deflickerWindowSize = deflickerWindowSize;

    this->reduceCameraShake = reduceCameraShake;

    this->ignorePerspective = ignorePerspective;

    this->motionDenoiser = motionDenoiser;

    this->isGaussian = isGaussian;

    this->isFast = isFast;

    this->bufferSize = bufferSize; //for median filter

    this->videoBuffer = new cv::Mat[bufferSize];

    QString firstFrame = (QString)listOfFiles.first();
    matOriginal = cv::imread(directory.filePath(firstFrame).toStdString(), CV_LOAD_IMAGE_COLOR);

    this->deflickerBufferMean = new cv::Scalar[deflickerWindowSize];
    this->deflickerBufferStd = new cv::Scalar[deflickerWindowSize];

    this->imgWidth = matOriginal.cols * imgHeight / matOriginal.rows;

    this->cropSize = cv::Rect((imgWidth * cropSize) / 100, (imgHeight * cropSize) / 100, (imgWidth * (100 - 2 * cropSize)) / 100, (imgHeight * (100 - 2 * cropSize)) / 100);

    this->frameRate = frameRate;

    videoWriter.open(directory.filePath(outputFilename).toStdString(), -1, this->frameRate, cv::Size(this->cropSize.width, this->cropSize.height));

    if (videoWriter.isOpened())
    {
        this->isVideoOpened = true;
    }
    else
    {
        this->isVideoOpened = false;
    }

}

void ProcessThread::run()
{
    //Iterate through frames
    progressCounter = 0;
    QList<QString>::iterator it;
    bufferCounter = 0;
    for (it = listOfFiles.begin(); it != listOfFiles.end(); ++it)
    {
        QMutex mutex;
        mutex.lock();

        if(!this->isVideoOpened) break;

        matOriginal = cv::imread(directory.filePath(*it).toStdString(), CV_LOAD_IMAGE_COLOR);
        cv::resize(matOriginal, matOriginal, cv::Size(imgWidth, imgHeight));

        videoBuffer[bufferCounter%bufferSize] = matOriginal;

        if(deflicker)
        {
            deflickerCurrentFrame();
        }

        if(reduceCameraShake && bufferCounter > 0)
        {
            reduceCameraShakeForCurrentFrame();
        }

        if(motionDenoiser && bufferCounter >= bufferSize)
        {
            //this function writes directly to the output file
            denoiseMotionforCurrentFrame();
        }
        else
        {
            videoWriter.write(videoBuffer[(bufferCounter)%bufferSize](cropSize));
        }

        bufferCounter++;

        progressCounter++;

        mutex.unlock();

        emit progressBarChanged(progressCounter*100/listOfFiles.length());

    }

    videoWriter.release();

    emit progressFinished();
}

bool ProcessThread::isGoodHomography(cv::Mat H)
{
    double det = H.at<double>(0, 0) * H.at<double>(1, 1) - H.at<double>(1, 0) * H.at<double>(0, 1);

    double theta = 3;

    if( fabs(det)< 1/theta || fabs(det)> theta)
            return false;

    return true;
}

void ProcessThread::denoiseMotionforCurrentFrame()
{
    //Warning: Does not modify the video buffer but writes the frame to the output file
    cv::Mat denoisedImg;
    videoBuffer[(bufferCounter)%bufferSize].copyTo(denoisedImg);

    int N = bufferSize;

    if(isGaussian)
    {
        denoisedImg = 0;
        double sigma = (double)N/3;
        double *gMask = new double[N];
        double gSum = 0;

        //prepare the Gaussian Mask
        for(int w = 0; w < N; w++)
        {
            gMask[w] = exp(-w*w/(2*sigma*sigma));
            gSum += gMask[w];
        }

        for(int w = 0; w < N; w++)
        {
            denoisedImg += (N*gMask[w]/gSum) * videoBuffer[(bufferCounter-w)%bufferSize]/N;
        }
    }
    else
    {
        std::vector<uchar> medianPixels(N,0);

        for(int i = 0; i < denoisedImg.rows; i++){
            for(int j = 0; j < denoisedImg.cols; j++){
                for(int c = 0; c < denoisedImg.channels(); c++){

                    //median of N frames
                    for(int w = 0; w < N; w++)
                    {
                        medianPixels[w] = videoBuffer[(bufferCounter-w)%bufferSize].data[denoisedImg.step[0]*i+ denoisedImg.step[1]*j + c];
                    }
                    std::sort(medianPixels.begin(), medianPixels.end());
                    denoisedImg.data[denoisedImg.step[0]*i+ denoisedImg.step[1]*j + c] = medianPixels[N/2];

                }

            }
        }
    }
    videoWriter.write(denoisedImg(cropSize));
}

void ProcessThread::deflickerCurrentFrame()
{
    //Warning: Modifies the video buffer

    //find average intensity and standard deviation for each color channel of the frame
    cv::meanStdDev(videoBuffer[bufferCounter%bufferSize], deflickerBufferMean[bufferCounter%deflickerWindowSize], deflickerBufferStd[bufferCounter%deflickerWindowSize]);

    cv::Scalar evCorrection;
    cv::Scalar contrastCorrection;

    //initialize buffer sum
    cv::Scalar bufferAvg = 0;
    cv::Scalar bufferStdAvg = 0;

    if(bufferCounter >= deflickerWindowSize)
    {
        for(int i = 0; i < deflickerWindowSize; i++)
        {
           bufferAvg += deflickerBufferMean[i]/cv::Scalar(deflickerWindowSize);
           bufferStdAvg += deflickerBufferStd[i]/cv::Scalar(deflickerWindowSize);
        }

        evCorrection = bufferAvg;
        contrastCorrection = bufferStdAvg;
    }
    else if(bufferCounter > 0)
    {
        for(int i = 0; i < bufferCounter; i++)
        {
           bufferAvg += deflickerBufferMean[i]/cv::Scalar(bufferCounter);
           bufferStdAvg += deflickerBufferStd[i]/cv::Scalar(bufferCounter);
        }

        evCorrection = bufferAvg;
        contrastCorrection = bufferStdAvg;
    }
    else
    {
        evCorrection = deflickerBufferMean[bufferCounter%deflickerWindowSize];
        contrastCorrection = deflickerBufferStd[bufferCounter%deflickerWindowSize];
    }

    cv::Mat doubleImg;
    videoBuffer[bufferCounter%bufferSize].convertTo(doubleImg, CV_64FC3);
    std::vector<cv::Mat> channels;
    split(doubleImg,channels);

    for(int ch = 0; ch < videoBuffer[bufferCounter%bufferSize].channels(); ch++)
    {
        channels[ch] = ((channels[ch] - deflickerBufferMean[bufferCounter%deflickerWindowSize][ch])/deflickerBufferStd[bufferCounter%deflickerWindowSize][ch])
                * contrastCorrection[ch] + evCorrection[ch];
    }
    cv::merge(channels,doubleImg);

    doubleImg.convertTo(videoBuffer[bufferCounter%bufferSize], CV_8UC3);
}

void ProcessThread::reduceCameraShakeForCurrentFrame()
{
    //Warning: Modifies the video buffer

    bool isBadMatch = false;

    cv::Mat frame1;
    cv::Mat frame2;

    cv::cvtColor(videoBuffer[(bufferCounter-1)%bufferSize], frame1, cv::COLOR_BGR2GRAY);
    cv::cvtColor(videoBuffer[(bufferCounter)%bufferSize], frame2, cv::COLOR_BGR2GRAY);

    cv::Mat transformMatrix;

    std::vector<cv::Point2f> frame1_points;
    std::vector<cv::Point2f> frame2_points;

    if(!isFast)
    {
        cv::SurfFeatureDetector detector( 400 );
        cv::SurfDescriptorExtractor extractor;

        std::vector<cv::KeyPoint> keypoints_frame1, keypoints_frame2;
        cv::Mat descriptors_frame1, descriptors_frame2;
        cv::FlannBasedMatcher matcher;

        detector.detect( frame1, keypoints_frame1 );
        detector.detect( frame2, keypoints_frame2 );

        extractor.compute( frame1, keypoints_frame1, descriptors_frame1 );
        extractor.compute( frame2, keypoints_frame2, descriptors_frame2 );

        std::vector< cv::DMatch > matches;
        matcher.match( descriptors_frame1, descriptors_frame2, matches );

        double max_dist = 0; double min_dist = 100;

        //-- Quick calculation of max and min distances between keypoints
        for( int i = 0; i < descriptors_frame1.rows; i++ )
        { double dist = matches[i].distance;
          if( dist < min_dist ) min_dist = dist;
          if( dist > max_dist ) max_dist = dist;
        }

        std::vector< cv::DMatch > good_matches;

        for( int i = 0; i < descriptors_frame1.rows; i++ )
        { if( matches[i].distance < 3*min_dist )
           { good_matches.push_back( matches[i]); }
        }

        for( unsigned int i = 0; i < good_matches.size(); i++ )
        {
          //-- Get the keypoints from the good matches
          frame1_points.push_back( keypoints_frame1[ good_matches[i].queryIdx ].pt );
          frame2_points.push_back( keypoints_frame2[ good_matches[i].trainIdx ].pt );
        }

        if(good_matches.size() < 4)
        {
            isBadMatch = true;
        }
        else if(ignorePerspective)
        {
            transformMatrix = estimateRigidTransform(frame2_points, frame1_points, 0);
        }
        else
        {
            transformMatrix = cv::findHomography(frame2_points, frame1_points, CV_RANSAC);
        }

    }
    else
    {
        cv::TermCriteria termcrit(cv::TermCriteria::COUNT|cv::TermCriteria::EPS,20,0.03);
        cv::Size subPixWinSize(10,10), winSize(31,31);

        cv::goodFeaturesToTrack(frame1, frame1_points, 500, 0.01, 10, cv::Mat(), 3, 0, 0.04);
        cv::cornerSubPix(frame1, frame1_points, subPixWinSize, cv::Size(-1,-1), termcrit);
        std::vector<uchar> status;
        std::vector<float> err;

        cv::calcOpticalFlowPyrLK(frame1, frame2, frame1_points, frame2_points, status, err, winSize,
                                         3, termcrit, 0, 0.001);


        if(ignorePerspective)
        {
             transformMatrix = estimateRigidTransform(frame2_points, frame1_points, 0);
        }
        else
        {
            transformMatrix = cv::findHomography(frame2_points, frame1_points, CV_RANSAC);
        }

    }

    if(!isBadMatch)
    if(isGoodHomography(transformMatrix))
    {
        if(ignorePerspective)
        {
            cv::warpAffine(videoBuffer[(bufferCounter)%bufferSize],
                           videoBuffer[(bufferCounter)%bufferSize],
                           transformMatrix, cv::Size(imgWidth, imgHeight),
                           cv::INTER_CUBIC);
        }
        else
        {
            cv::warpPerspective(videoBuffer[(bufferCounter)%bufferSize],
                                videoBuffer[(bufferCounter)%bufferSize],
                                transformMatrix, cv::Size(imgWidth, imgHeight),
                                cv::INTER_CUBIC);
        }
    }
}
