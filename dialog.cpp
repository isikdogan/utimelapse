#include "dialog.h"
#include "ui_dialog.h"
#include "infobox.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags() | Qt::WindowMinimizeButtonHint);

    processThread = new ProcessThread(this);
    connect(processThread, SIGNAL(progressBarChanged(int)), this, SLOT(on_progressBarChanged(int)));
    connect(processThread, SIGNAL(progressFinished()), this, SLOT(on_progressFinished()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_openDirectoryButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory (this, tr("Directory"), directory.path());
    if ( path.isNull() == false )
    {
        directory.setPath(path);

        QStringList nameFilter;
        nameFilter << "*.jpg" << "*.jpeg" << "*.jpe" << "*.bmp" << "*.dib" << "*.jp2" << "*.png" << "*.pbm" << "*.pgm" << "*.ppm" << "*.tiff" << "*.tiff";
        listOfFiles = directory.entryList(nameFilter);
        if (listOfFiles.length() < 2)
        {
            msgBox.setWindowTitle("Error!");
            msgBox.setText("There should be at least 2 images in the directory!");
            msgBox.exec();
        }
        else
        {
            ui->txtOutput->setText(directory.path());
            ui->runButton->setEnabled(true);
        }
    }
    else
    {
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Cannot open the directory!");
        msgBox.exec();
    }

}

void Dialog::on_runButton_clicked()
{
    processThread->setParameters(ui->resolutionComboBox->currentIndex(), directory, listOfFiles,
                                 ui->frameRateSlider->value(),
                                 ui->checkBoxDeflicker->isChecked(),
                                 ui->windowSizeSlider->value(),
                                 ui->checkBoxMedian->isChecked(),
                                 ui->checkBoxGaussian->isChecked(),
                                 ui->windowSizeSliderMedian->value()*2+1,
                                 ui->checkBoxCameraShake->isChecked(),
                                 ui->checkBoxNoPerspective->isChecked(),
                                 ui->croppingSlider->value(),
                                 ui->radioButtonFast->isChecked(),
                                 ui->txtOutputFile->text());

    if(!processThread->isVideoOpened)
    {
        msgBox.setWindowTitle("Error!");
        msgBox.setText("The output video cannot be created/opened!");
        msgBox.exec();
        return;
    }

    //Disable GUI elements while processing
    ui->openDirectoryButton->setEnabled(false);
    ui->frameRateSlider->setEnabled(false);
    ui->resolutionComboBox->setEnabled(false);
    ui->runButton->setEnabled(false);
    ui->checkBoxCameraShake->setEnabled(false);
    ui->checkBoxDeflicker->setEnabled(false);
    ui->checkBoxMedian->setEnabled(false);
    ui->label_framerate->setEnabled(false);
    ui->label_resolution->setEnabled(false);
    ui->frameRateLabel->setEnabled(false);
    ui->groupBoxCameraShake->setEnabled(false);
    ui->cropLabel->setEnabled(false);
    ui->label_crop->setEnabled(false);
    ui->croppingSlider->setEnabled(false);
    ui->windowSizeSlider->setEnabled(false);
    ui->label_windowsize->setEnabled(false);
    ui->windowLabel->setEnabled(false);

    ui->windowLabelMedian->setEnabled(false);
    ui->checkBoxGaussian->setEnabled(false);
    ui->windowSizeSliderMedian->setEnabled(false);
    ui->label_windowsizemedian->setEnabled(false);

    ui->abortButton->setEnabled(true);

    processThread->start();
    //processThread->wait();
    //processThread->run();
}

void Dialog::on_frameRateSlider_valueChanged(int value)
{
    ui->frameRateLabel->setText(QString::fromStdString(std::to_string((long long)value)));
}

void Dialog::on_progressBarChanged(int i)
{
    ui->progressBar->setValue(i);
}

void Dialog::on_progressFinished()
{
    msgBox.setWindowTitle("Success!");
    msgBox.setText("The output video has been created successfully!");
    msgBox.exec();

    //Reset GUI elements
    ui->openDirectoryButton->setEnabled(true);
    ui->frameRateSlider->setEnabled(true);
    ui->resolutionComboBox->setEnabled(true);
    ui->runButton->setEnabled(true);
    ui->checkBoxCameraShake->setEnabled(true);
    ui->checkBoxDeflicker->setEnabled(true);
    ui->checkBoxMedian->setEnabled(true);
    ui->label_framerate->setEnabled(true);
    ui->label_resolution->setEnabled(true);
    ui->frameRateLabel->setEnabled(true);

    if(ui->checkBoxDeflicker->isChecked())
    {
        ui->windowSizeSlider->setEnabled(true);
        ui->label_windowsize->setEnabled(true);
        ui->windowLabel->setEnabled(true);
    }

    if(ui->checkBoxCameraShake->isChecked())
    {
        ui->groupBoxCameraShake->setEnabled(true);
        ui->cropLabel->setEnabled(true);
        ui->label_crop->setEnabled(true);
        ui->croppingSlider->setEnabled(true);
    }

    if(ui->checkBoxMedian->isChecked())
    {
        ui->checkBoxGaussian->setEnabled(true);
        ui->windowLabelMedian->setEnabled(true);
        ui->windowSizeSliderMedian->setEnabled(true);
        ui->label_windowsizemedian->setEnabled(true);
    }

    ui->progressBar->reset();
}

void Dialog::on_checkBoxCameraShake_toggled(bool checked)
{
    ui->groupBoxCameraShake->setEnabled(checked);
    ui->cropLabel->setEnabled(checked);
    ui->label_crop->setEnabled(checked);
    ui->croppingSlider->setEnabled(checked);
    if(!checked)
        ui->croppingSlider->setValue(0);
}

void Dialog::on_croppingSlider_valueChanged(int value)
{
    ui->cropLabel->setText(QString::fromStdString(std::to_string((long long)value)));
}

void Dialog::on_windowSizeSlider_valueChanged(int value)
{
    ui->windowLabel->setText(QString::fromStdString(std::to_string((long long)value)));
}

void Dialog::on_checkBoxDeflicker_toggled(bool checked)
{
    ui->windowSizeSlider->setEnabled(checked);
    ui->windowLabel->setEnabled(checked);
    ui->label_windowsize->setEnabled(checked);
}

void Dialog::on_pushButtonInfo_clicked()
{
    InfoBox aboutUi;
    aboutUi.exec();
}

void Dialog::on_checkBoxMedian_toggled(bool checked)
{
    ui->windowLabelMedian->setEnabled(checked);
    ui->windowSizeSliderMedian->setEnabled(checked);
    ui->label_windowsizemedian->setEnabled(checked);
    ui->checkBoxGaussian->setEnabled(checked);
}

void Dialog::on_windowSizeSliderMedian_valueChanged(int value)
{
    ui->windowLabelMedian->setText(QString::fromStdString(std::to_string((long long)(value*2+1))));
}

void Dialog::on_abortButton_clicked()
{
    ui->abortButton->setEnabled(false);
    processThread->terminate();

    //Reset GUI elements
    ui->openDirectoryButton->setEnabled(true);
    ui->frameRateSlider->setEnabled(true);
    ui->resolutionComboBox->setEnabled(true);
    ui->runButton->setEnabled(true);
    ui->checkBoxCameraShake->setEnabled(true);
    ui->checkBoxDeflicker->setEnabled(true);
    ui->checkBoxMedian->setEnabled(true);
    ui->label_framerate->setEnabled(true);
    ui->label_resolution->setEnabled(true);
    ui->frameRateLabel->setEnabled(true);

    if(ui->checkBoxDeflicker->isChecked())
    {
        ui->windowSizeSlider->setEnabled(true);
        ui->label_windowsize->setEnabled(true);
        ui->windowLabel->setEnabled(true);
    }

    if(ui->checkBoxCameraShake->isChecked())
    {
        ui->groupBoxCameraShake->setEnabled(true);
        ui->cropLabel->setEnabled(true);
        ui->label_crop->setEnabled(true);
        ui->croppingSlider->setEnabled(true);
    }

    if(ui->checkBoxMedian->isChecked())
    {
        ui->checkBoxGaussian->setEnabled(true);
        ui->windowLabelMedian->setEnabled(true);
        ui->windowSizeSliderMedian->setEnabled(true);
        ui->label_windowsizemedian->setEnabled(true);
    }

    ui->progressBar->reset();
}
