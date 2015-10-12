#-------------------------------------------------
#
# Project created by QtCreator 2014-02-12T02:18:15
#
#-------------------------------------------------

QT       += core gui

TARGET = UTimelapse
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    processthread.cpp \
    infobox.cpp

HEADERS  += dialog.h \
    processthread.h \
    infobox.h

FORMS    += dialog.ui \
    infobox.ui
CONFIG += static

INCLUDEPATH += C:\\OpenCV-2.4.2\\opencv\\build\\include

RESOURCES = resources.qrc

QT += gui declarative

LIBS += -LC:/OpenCV-2.4.2/opencv/build/x86/vc10/lib \
        -lopencv_core242d \
        -lopencv_highgui242d \
        -lopencv_imgproc242d \
        -lopencv_features2d242d \
        -lopencv_calib3d242d \
        -lopencv_nonfree242d \
        -lopencv_flann242d \
        -lopencv_video242d \
        -lopencv_videostab242d
