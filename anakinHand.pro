#-------------------------------------------------
#
# Project created by QtCreator 2013-09-09T16:42:58
#
#-------------------------------------------------

QT       += serialport \
	core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = anakinHand
TEMPLATE = app


SOURCES += main.cpp\
        mainWindow.cpp \
	glove.cpp \
    hand.cpp \
    gloveInterface.cpp \
    user.cpp \
    action.cpp \
    calibrator.cpp \
    translator.cpp \
    handInterface.cpp \
	actionPerfomer.cpp \
    kalmanFilter.cpp

HEADERS  += mainWindow.h \
    glove.h \
    hand.h \
    gloveInterface.h \
    user.h \
    action.h \
    calibrator.h \
    translator.h \
    handInterface.h \
    consts.h \
    degreeOfFreedom.h \
	actionPerfomer.h \
    kalmanFilter.h

FORMS    += mainWindow.ui
