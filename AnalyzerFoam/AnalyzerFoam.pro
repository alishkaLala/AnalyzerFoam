#-------------------------------------------------
#
# Project created by QtCreator 2013-01-26T21:42:42
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

TARGET = AnalyzerFoam
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filewriteread.cpp \
    infoframe.cpp \
    settingmainframes.cpp \
    settingcaptureframe.cpp \
    configinformation.cpp \
    openglgraph.cpp \
    imageprocessing.cpp \
    converter.cpp \
    canal_contur.cpp

HEADERS  += mainwindow.h \
    filewriteread.h \
    infoframe.h \
    settingmainframes.h \
    settingcaptureframe.h \
    configinformation.h \
    openglgraph.h \
    imageprocessing.h \
    converter.h \
    canal_contur.h

FORMS    += mainwindow.ui \
    infoframe.ui \
    settingmainframes.ui \
    settingcaptureframe.ui

INCLUDEPATH += "C:\OpenCV2.0\include\opencv"

LIBS += "C:\OpenCV2.0\lib\libcv200.dll.a"
LIBS += "C:\OpenCV2.0\lib\libhighgui200.dll.a"
LIBS += "C:\OpenCV2.0\lib\libcxcore200.dll.a"

TRANSLATIONS = spreadsheet_de.ts \
               spreadsheet_fr.ts \
               spreadsheet_ru.ts

OTHER_FILES +=

RESOURCES += \
    resourses.qrc
