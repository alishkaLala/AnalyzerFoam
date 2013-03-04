#include <QtGui/QApplication>
#include "mainwindow.h"
#include <settingmainframes.h>
#include "settingcaptureframe.h"
#include <configinformation.h>
#include <calculation.h>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251"); //*****************************************************
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings (codec);


     //Calculation n ;
    // n.start();
    QTranslator translator;
    a.installTranslator(&translator);
    // SettingCaptureFrame s;
    // s.show();

    configInformation::initialize(a.applicationDirPath());

    //configInformation::setStandardPreference();

   //configInformation::writeToFile();
    configInformation::readFromFile();

    //s.startWork();


    MainWindow w;
     w.showing();


    //SettingMainFrames r;
    //r.show();
    //a.closingDown();

    return a.exec();



}
