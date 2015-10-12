#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QThread>
#include <QtCore>
#include <QDir>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/video/tracking.hpp>

class ProcessThread : public QThread
{
    Q_OBJECT
public:
    explicit ProcessThread(QObject *parent = 0);
    void setParameters(int resolutionIdx,
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
                       int cropSize,
                       bool isFast, QString outputFilename);
    void run();
    bool isGoodHomography(cv::Mat H);
    bool isVideoOpened;
    
private:
    int imgWidth;
    int imgHeight;
    int progressCounter;
    int frameRate;
    int bufferSize;
    int bufferCounter;
    int deflickerWindowSize;
    cv::Scalar* deflickerBufferMean;
    cv::Scalar* deflickerBufferStd;
    QDir directory;
    QStringList listOfFiles;
    cv::VideoWriter videoWriter;
    cv::VideoCapture videoReader;
    cv::Mat matOriginal;
    cv::Mat* videoBuffer;
    cv::Rect cropSize;
    bool deflicker;
    bool reduceCameraShake;
    bool ignorePerspective;
    bool isGaussian;
    bool motionDenoiser;
    bool isFast;
    QString outputFilename;

    void deflickerCurrentFrame();
    void reduceCameraShakeForCurrentFrame();
    void denoiseMotionforCurrentFrame();

signals:
    void progressBarChanged(int i);
    void progressFinished();
    
public slots:
    
};

#endif // PROCESSTHREAD_H
