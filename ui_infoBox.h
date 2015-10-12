/********************************************************************************
** Form generated from reading UI file 'infobox.ui'
**
** Created: Sun Apr 6 22:42:38 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOBOX_H
#define UI_INFOBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_InfoBox
{
public:
    QLabel *label;

    void setupUi(QDialog *InfoBox)
    {
        if (InfoBox->objectName().isEmpty())
            InfoBox->setObjectName(QString::fromUtf8("InfoBox"));
        InfoBox->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/utimelapse-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        InfoBox->setWindowIcon(icon);
        label = new QLabel(InfoBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 371, 261));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        retranslateUi(InfoBox);

        QMetaObject::connectSlotsByName(InfoBox);
    } // setupUi

    void retranslateUi(QDialog *InfoBox)
    {
        InfoBox->setWindowTitle(QApplication::translate("InfoBox", "Help & Info", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InfoBox", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Version: 1.02</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Release Date: April 6, 2014</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Author: Furkan Isikdogan</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:"
                        "0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Homepage: </span><a href=\"http://www.isikdogan.com\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">www.isikdogan.com</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfoBox: public Ui_InfoBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOBOX_H
