#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QGroupBox>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/video/tracking.hpp>

#include "processthread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    ProcessThread *processThread;

private:
    Ui::Dialog *ui;
    QDir directory;
    QStringList listOfFiles;
    QMessageBox msgBox;

private slots:
    void on_openDirectoryButton_clicked();
    void on_runButton_clicked();
    void on_frameRateSlider_valueChanged(int value);
    void on_progressBarChanged(int i);
    void on_progressFinished();
    void on_checkBoxCameraShake_toggled(bool checked);
    void on_croppingSlider_valueChanged(int value);
    void on_windowSizeSlider_valueChanged(int value);
    void on_checkBoxDeflicker_toggled(bool checked);
    void on_pushButtonInfo_clicked();
    void on_checkBoxMedian_toggled(bool checked);
    void on_windowSizeSliderMedian_valueChanged(int value);
    void on_abortButton_clicked();
};

#endif // DIALOG_H
