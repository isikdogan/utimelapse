/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Tue Apr 29 18:42:30 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *openDirectoryButton;
    QSlider *frameRateSlider;
    QLabel *frameRateLabel;
    QLabel *label_framerate;
    QPushButton *runButton;
    QComboBox *resolutionComboBox;
    QLabel *label_resolution;
    QProgressBar *progressBar;
    QLineEdit *txtOutput;
    QCheckBox *checkBoxMedian;
    QCheckBox *checkBoxDeflicker;
    QGroupBox *groupBoxCameraShake;
    QLabel *cropLabel;
    QLabel *label_crop;
    QSlider *croppingSlider;
    QRadioButton *radioButtonFast;
    QRadioButton *radioButtonRobust;
    QCheckBox *checkBoxNoPerspective;
    QCheckBox *checkBoxCameraShake;
    QGroupBox *groupBoxDeflickering;
    QLabel *label_windowsize;
    QSlider *windowSizeSlider;
    QLabel *windowLabel;
    QLabel *label;
    QPushButton *pushButtonInfo;
    QLineEdit *txtOutputFile;
    QLabel *label_2;
    QGroupBox *groupBoxMedian;
    QLabel *windowLabelMedian;
    QSlider *windowSizeSliderMedian;
    QLabel *label_windowsizemedian;
    QCheckBox *checkBoxGaussian;
    QPushButton *abortButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(465, 455);
        Dialog->setMinimumSize(QSize(465, 455));
        Dialog->setMaximumSize(QSize(465, 455));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/utimelapse-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        openDirectoryButton = new QPushButton(Dialog);
        openDirectoryButton->setObjectName(QString::fromUtf8("openDirectoryButton"));
        openDirectoryButton->setGeometry(QRect(10, 70, 131, 23));
        frameRateSlider = new QSlider(Dialog);
        frameRateSlider->setObjectName(QString::fromUtf8("frameRateSlider"));
        frameRateSlider->setGeometry(QRect(10, 210, 191, 20));
        frameRateSlider->setMinimum(1);
        frameRateSlider->setMaximum(60);
        frameRateSlider->setValue(24);
        frameRateSlider->setSliderPosition(24);
        frameRateSlider->setOrientation(Qt::Horizontal);
        frameRateLabel = new QLabel(Dialog);
        frameRateLabel->setObjectName(QString::fromUtf8("frameRateLabel"));
        frameRateLabel->setGeometry(QRect(210, 210, 21, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        frameRateLabel->setFont(font);
        label_framerate = new QLabel(Dialog);
        label_framerate->setObjectName(QString::fromUtf8("label_framerate"));
        label_framerate->setGeometry(QRect(10, 190, 61, 16));
        runButton = new QPushButton(Dialog);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setEnabled(false);
        runButton->setGeometry(QRect(390, 410, 61, 31));
        resolutionComboBox = new QComboBox(Dialog);
        resolutionComboBox->setObjectName(QString::fromUtf8("resolutionComboBox"));
        resolutionComboBox->setGeometry(QRect(10, 150, 211, 22));
        label_resolution = new QLabel(Dialog);
        label_resolution->setObjectName(QString::fromUtf8("label_resolution"));
        label_resolution->setGeometry(QRect(10, 130, 61, 16));
        progressBar = new QProgressBar(Dialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 420, 321, 23));
        progressBar->setValue(0);
        txtOutput = new QLineEdit(Dialog);
        txtOutput->setObjectName(QString::fromUtf8("txtOutput"));
        txtOutput->setEnabled(false);
        txtOutput->setGeometry(QRect(150, 70, 301, 20));
        txtOutput->setReadOnly(true);
        checkBoxMedian = new QCheckBox(Dialog);
        checkBoxMedian->setObjectName(QString::fromUtf8("checkBoxMedian"));
        checkBoxMedian->setGeometry(QRect(240, 280, 221, 17));
        checkBoxDeflicker = new QCheckBox(Dialog);
        checkBoxDeflicker->setObjectName(QString::fromUtf8("checkBoxDeflicker"));
        checkBoxDeflicker->setGeometry(QRect(240, 180, 91, 17));
        groupBoxCameraShake = new QGroupBox(Dialog);
        groupBoxCameraShake->setObjectName(QString::fromUtf8("groupBoxCameraShake"));
        groupBoxCameraShake->setEnabled(false);
        groupBoxCameraShake->setGeometry(QRect(10, 270, 211, 121));
        cropLabel = new QLabel(groupBoxCameraShake);
        cropLabel->setObjectName(QString::fromUtf8("cropLabel"));
        cropLabel->setEnabled(false);
        cropLabel->setGeometry(QRect(190, 90, 21, 20));
        cropLabel->setFont(font);
        label_crop = new QLabel(groupBoxCameraShake);
        label_crop->setObjectName(QString::fromUtf8("label_crop"));
        label_crop->setEnabled(false);
        label_crop->setGeometry(QRect(10, 70, 111, 16));
        croppingSlider = new QSlider(groupBoxCameraShake);
        croppingSlider->setObjectName(QString::fromUtf8("croppingSlider"));
        croppingSlider->setEnabled(false);
        croppingSlider->setGeometry(QRect(10, 90, 171, 20));
        croppingSlider->setMinimum(0);
        croppingSlider->setMaximum(25);
        croppingSlider->setPageStep(3);
        croppingSlider->setValue(0);
        croppingSlider->setSliderPosition(0);
        croppingSlider->setOrientation(Qt::Horizontal);
        radioButtonFast = new QRadioButton(groupBoxCameraShake);
        radioButtonFast->setObjectName(QString::fromUtf8("radioButtonFast"));
        radioButtonFast->setGeometry(QRect(10, 10, 82, 17));
        radioButtonFast->setChecked(true);
        radioButtonFast->setAutoRepeatDelay(100);
        radioButtonRobust = new QRadioButton(groupBoxCameraShake);
        radioButtonRobust->setObjectName(QString::fromUtf8("radioButtonRobust"));
        radioButtonRobust->setGeometry(QRect(80, 10, 82, 17));
        checkBoxNoPerspective = new QCheckBox(groupBoxCameraShake);
        checkBoxNoPerspective->setObjectName(QString::fromUtf8("checkBoxNoPerspective"));
        checkBoxNoPerspective->setGeometry(QRect(10, 40, 181, 17));
        checkBoxCameraShake = new QCheckBox(Dialog);
        checkBoxCameraShake->setObjectName(QString::fromUtf8("checkBoxCameraShake"));
        checkBoxCameraShake->setGeometry(QRect(10, 250, 151, 17));
        groupBoxDeflickering = new QGroupBox(Dialog);
        groupBoxDeflickering->setObjectName(QString::fromUtf8("groupBoxDeflickering"));
        groupBoxDeflickering->setGeometry(QRect(240, 200, 211, 61));
        label_windowsize = new QLabel(groupBoxDeflickering);
        label_windowsize->setObjectName(QString::fromUtf8("label_windowsize"));
        label_windowsize->setEnabled(false);
        label_windowsize->setGeometry(QRect(10, 10, 111, 16));
        windowSizeSlider = new QSlider(groupBoxDeflickering);
        windowSizeSlider->setObjectName(QString::fromUtf8("windowSizeSlider"));
        windowSizeSlider->setEnabled(false);
        windowSizeSlider->setGeometry(QRect(10, 30, 171, 20));
        windowSizeSlider->setMinimum(2);
        windowSizeSlider->setMaximum(99);
        windowSizeSlider->setPageStep(3);
        windowSizeSlider->setValue(48);
        windowSizeSlider->setSliderPosition(48);
        windowSizeSlider->setOrientation(Qt::Horizontal);
        windowLabel = new QLabel(groupBoxDeflickering);
        windowLabel->setObjectName(QString::fromUtf8("windowLabel"));
        windowLabel->setEnabled(false);
        windowLabel->setGeometry(QRect(190, 30, 21, 20));
        windowLabel->setFont(font);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 211, 51));
        label->setPixmap(QPixmap(QString::fromUtf8(":/utimelapse-logo-small.png")));
        pushButtonInfo = new QPushButton(Dialog);
        pushButtonInfo->setObjectName(QString::fromUtf8("pushButtonInfo"));
        pushButtonInfo->setGeometry(QRect(370, 10, 81, 23));
        pushButtonInfo->setDefault(false);
        pushButtonInfo->setFlat(false);
        txtOutputFile = new QLineEdit(Dialog);
        txtOutputFile->setObjectName(QString::fromUtf8("txtOutputFile"));
        txtOutputFile->setGeometry(QRect(150, 100, 301, 20));
        txtOutputFile->setReadOnly(false);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 81, 20));
        groupBoxMedian = new QGroupBox(Dialog);
        groupBoxMedian->setObjectName(QString::fromUtf8("groupBoxMedian"));
        groupBoxMedian->setGeometry(QRect(240, 300, 211, 91));
        windowLabelMedian = new QLabel(groupBoxMedian);
        windowLabelMedian->setObjectName(QString::fromUtf8("windowLabelMedian"));
        windowLabelMedian->setEnabled(false);
        windowLabelMedian->setGeometry(QRect(190, 60, 21, 20));
        windowLabelMedian->setFont(font);
        windowSizeSliderMedian = new QSlider(groupBoxMedian);
        windowSizeSliderMedian->setObjectName(QString::fromUtf8("windowSizeSliderMedian"));
        windowSizeSliderMedian->setEnabled(false);
        windowSizeSliderMedian->setGeometry(QRect(10, 60, 171, 20));
        windowSizeSliderMedian->setMinimum(1);
        windowSizeSliderMedian->setMaximum(3);
        windowSizeSliderMedian->setSingleStep(2);
        windowSizeSliderMedian->setPageStep(2);
        windowSizeSliderMedian->setValue(1);
        windowSizeSliderMedian->setSliderPosition(1);
        windowSizeSliderMedian->setOrientation(Qt::Horizontal);
        label_windowsizemedian = new QLabel(groupBoxMedian);
        label_windowsizemedian->setObjectName(QString::fromUtf8("label_windowsizemedian"));
        label_windowsizemedian->setEnabled(false);
        label_windowsizemedian->setGeometry(QRect(10, 40, 111, 16));
        checkBoxGaussian = new QCheckBox(groupBoxMedian);
        checkBoxGaussian->setObjectName(QString::fromUtf8("checkBoxGaussian"));
        checkBoxGaussian->setEnabled(false);
        checkBoxGaussian->setGeometry(QRect(10, 10, 221, 17));
        abortButton = new QPushButton(Dialog);
        abortButton->setObjectName(QString::fromUtf8("abortButton"));
        abortButton->setEnabled(false);
        abortButton->setGeometry(QRect(330, 410, 61, 31));

        retranslateUi(Dialog);

        resolutionComboBox->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "UTimelapse: The Ultra HD Timelapse Tool", 0, QApplication::UnicodeUTF8));
        openDirectoryButton->setText(QApplication::translate("Dialog", "Open Image Directory", 0, QApplication::UnicodeUTF8));
        frameRateLabel->setText(QApplication::translate("Dialog", "24", 0, QApplication::UnicodeUTF8));
        label_framerate->setText(QApplication::translate("Dialog", "Frame Rate", 0, QApplication::UnicodeUTF8));
        runButton->setText(QApplication::translate("Dialog", "Run!", 0, QApplication::UnicodeUTF8));
        resolutionComboBox->clear();
        resolutionComboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "240p", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "360p", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "480p", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "720p", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "1080p", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "4K", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "8K", 0, QApplication::UnicodeUTF8)
        );
        label_resolution->setText(QApplication::translate("Dialog", "Resolution", 0, QApplication::UnicodeUTF8));
        checkBoxMedian->setText(QApplication::translate("Dialog", "Temporal Denoising / Artifact Removal", 0, QApplication::UnicodeUTF8));
        checkBoxDeflicker->setText(QApplication::translate("Dialog", "Deflickering", 0, QApplication::UnicodeUTF8));
        groupBoxCameraShake->setTitle(QString());
        cropLabel->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        label_crop->setText(QApplication::translate("Dialog", "Margin Cropping Rate", 0, QApplication::UnicodeUTF8));
        radioButtonFast->setText(QApplication::translate("Dialog", "Fast", 0, QApplication::UnicodeUTF8));
        radioButtonRobust->setText(QApplication::translate("Dialog", "Robust", 0, QApplication::UnicodeUTF8));
        checkBoxNoPerspective->setText(QApplication::translate("Dialog", "Assume no perspective change", 0, QApplication::UnicodeUTF8));
        checkBoxCameraShake->setText(QApplication::translate("Dialog", "Camera Shake Reduction", 0, QApplication::UnicodeUTF8));
        groupBoxDeflickering->setTitle(QString());
        label_windowsize->setText(QApplication::translate("Dialog", "Window Size", 0, QApplication::UnicodeUTF8));
        windowLabel->setText(QApplication::translate("Dialog", "48", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButtonInfo->setText(QApplication::translate("Dialog", "Help / Info", 0, QApplication::UnicodeUTF8));
        txtOutputFile->setText(QApplication::translate("Dialog", "outputVideo.avi", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Output Filename", 0, QApplication::UnicodeUTF8));
        groupBoxMedian->setTitle(QString());
        windowLabelMedian->setText(QApplication::translate("Dialog", "3", 0, QApplication::UnicodeUTF8));
        label_windowsizemedian->setText(QApplication::translate("Dialog", "Window Size", 0, QApplication::UnicodeUTF8));
        checkBoxGaussian->setText(QApplication::translate("Dialog", "Motion Smoothing", 0, QApplication::UnicodeUTF8));
        abortButton->setText(QApplication::translate("Dialog", "Abort", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
