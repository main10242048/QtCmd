#-------------------------------------------------
#
# Project created by QtCreator 2018-10-09T15:11:32
#
#-------------------------------------------------

QT       += core gui
QT       += xml
TARGET = QtCmd
TEMPLATE = app


SOURCES += main.cpp\
        QtCmdDlg.cpp \
    QUtility/Keyboard/keyboard.cpp \
    QUtility/Keyboard/bigKeyboard.cpp \
    stdafx.cpp

HEADERS  += QtCmdDlg.h \
    QUtility/myhelper.h \
    QUtility/Keyboard/keyboard.h \
    QUtility/Keyboard/bigKeyboard.h \
    stdafx.h

FORMS    += QtCmdDlg.ui \
    QUtility/Keyboard/keyboard.ui \
    QUtility/Keyboard/bigKeyboard.ui
