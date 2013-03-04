#include "configinformation.h"


#include <QMessageBox>
#include <QDebug>

QSettings *configInformation::file;

bool configInformation::initialize(QString a)
{

    file = new QSettings(a+"/configuration.ini", QSettings::IniFormat);

}
void configInformation::setStandardPreference()
{
   setStandardPreferenceCapture();

   palleteAllWindows = QApplication::palette(); ///??????????????????????????????????????????
   nameFile= "default.txt";
   rewrite = true;
   firstWriteDate = true;
   font = QApplication::font();

}

void configInformation::setStandardPreferenceCapture()
{
   sizeWindowCaptureMinimum=300;
   sizeWindowCaptureMaximum=800;
   sizeWindowCaptureNow= 400;

   distanceInMmMinimum=0.01;
   distanceInMmMaximum=100;
   distanceInMmNow = 10;

   periodCaptureMinimum= 20;
   periodCaptureMaximum = 120;
   periodCaptureNow = 40;

   captureNumber = 0;

   frameWidth = 300,frameHight= 300;
   frameWidthResize = 0 ,frameHightResize =0 ;
   X1Resize=0,Y1Resize=0;
   coefficient=1;
   coefficientResize =1;



   distanceInPixels = 10;

   enabledResize = false;

}


bool configInformation::writeToFile()
{
    file->beginGroup("sizeWindowCapture");
    file->setValue("sizeWindowCaptureMinimum",sizeWindowCaptureMinimum);
    file->setValue("sizeWindowCaptureMaximum",sizeWindowCaptureMaximum);
    file->setValue("sizeWindowCaptureNow",sizeWindowCaptureNow);
    file->endGroup();
    file->sync();

    file->beginGroup("distanceInMm");
    file->setValue("distanceInMmMinimum",distanceInMmMinimum);
    file->setValue("distanceInMmMaximum",distanceInMmMaximum);
    file->setValue("distanceInMmNow",distanceInMmNow);
    file->endGroup();
    file->sync();

    file->beginGroup("periodCapture");
    file->setValue("periodCaptureMinimum",periodCaptureMinimum);
    file->setValue("periodCaptureMaximum",periodCaptureMaximum);
    file->setValue("periodCaptureNow",periodCaptureNow);
    file->endGroup();
    file->sync();


    file->beginGroup("periodCapture");
    file->setValue("captureNumber",captureNumber);
    file->endGroup();
    file->sync();

    file->beginGroup("Frame");
    file->setValue("frameWidth",frameWidth);
    file->setValue("frameHight",frameHight);
    file->setValue("frameWidthResize",frameWidthResize),
    file->setValue("frameHightResize",frameHightResize);
    file->setValue("X1Resize",X1Resize),
    file->setValue("Y1Resize",Y1Resize);
    file->setValue("coefficient",coefficient);
    file->setValue("coefficientResize",coefficientResize);
    file->endGroup();
    file->sync();



    file->beginGroup("distance");
    file->setValue("distanceInPixels",distanceInPixels);
    file->endGroup();
    file->sync();

    file->beginGroup("isResizing");
    file->setValue("denabledResize",enabledResize);
    file->endGroup();
    file->sync();

    file->beginGroup("gui");
    file->setValue("palleteAllWindows",palleteAllWindows);
    file->setValue("font",font);
    file->endGroup();
    file->sync();

    file->beginGroup("file");
    file->setValue("nameFile",nameFile);
    file->setValue("rewrite",rewrite);
    file->setValue("firstWriteDate",firstWriteDate);
    file->endGroup();
    file->sync();

    return true;

}
bool configInformation::readFromFile()
{

    file->beginGroup("sizeWindowCapture");
    sizeWindowCaptureMinimum= file->value("sizeWindowCaptureMinimum").toInt();
    sizeWindowCaptureMaximum= file->value("sizeWindowCaptureMaximum").toInt();
    sizeWindowCaptureNow=file->value("sizeWindowCaptureNow").toInt();
    file->endGroup();
    file->sync();

    file->beginGroup("distanceInMm");
    distanceInMmMinimum=file->value("distanceInMmMinimum").toInt();
    distanceInMmMaximum=file->value("distanceInMmMaximum").toInt();
    distanceInMmNow=file->value("distanceInMmNow").toInt();
    file->endGroup();
    file->sync();

    file->beginGroup("periodCapture");
    periodCaptureMinimum=file->value("periodCaptureMinimum").toInt();
    periodCaptureMaximum=file->value("periodCaptureMaximum").toInt();
    periodCaptureNow=file->value("periodCaptureNow").toInt();
    file->endGroup();
    file->sync();


    file->beginGroup("periodCapture");
    captureNumber=file->value("captureNumber").toInt();
    file->endGroup();
    file->sync();

    file->beginGroup("Frame");
    frameWidth=file->value("frameWidth").toInt();
    frameHight=file->value("frameHight").toInt();
    X1Resize=file->value("X1Resize").toInt(),
    Y1Resize=file->value("Y1Resize").toInt();
    frameWidthResize=file->value("frameWidthResize").toInt(),
    frameHightResize=file->value("frameHightResize").toInt();
    coefficient=file->value("coefficient").toDouble();
    coefficientResize=file->value("coefficientResize").toDouble();
    file->endGroup();
    file->sync();



    file->beginGroup("distance");
    distanceInPixels=file->value("distanceInPixels").toInt();
    file->endGroup();
    file->sync();

    file->beginGroup("isResizing");
    enabledResize=file->value("denabledResize").toBool();
    file->endGroup();
    file->sync();

    file->beginGroup("gui");
    palleteAllWindows=file->value("palleteAllWindows").value<QPalette>();
    font=file->value("font").value<QFont>();
    file->endGroup();
    file->sync();

    file->beginGroup("file");
    nameFile=file->value("nameFile").toString();
    rewrite=file->value("rewrite").toBool();
    firstWriteDate=file->value("firstWriteDate").toBool();
    file->endGroup();
    file->sync();

    return true;

}

bool configInformation::setSizeWindowCapture(qint32 size)
{
    if(sizeWindowCaptureMinimum<=size && sizeWindowCaptureMaximum>= size)
    {
        sizeWindowCaptureNow= size;
        return true;
    }
    else return false;
}
qint32 configInformation::getSizeWindowCapture()
{
    return sizeWindowCaptureNow;
}


bool configInformation::setperiodCapture(qint32 size)
{
    if(periodCaptureMinimum<=size && periodCaptureMaximum>= size)
    {
        periodCaptureNow = size;
        return true;
    }
    else return false;
}
qint32 configInformation::getperiodCapture()
{
    return periodCaptureNow;
}


qint32 configInformation::getCaptureNumber(){
    return configInformation::captureNumber;

}
bool configInformation::setCaptureNumber(qint32 N){
    if(N>=0 && N<=10){
        configInformation::captureNumber=N;
        return true;
    }
    else{
        return false;
    }

}


bool configInformation::setframeWidthAndFrameHight(qint32 w,qint32 h){

    if (w>0 && h>0){
        frameWidth=w;
        frameHight=h;
        return true;
    }
    else{
        return false;
    }



}
bool configInformation::setframeWidthResizeAndframeHightResize(qint32 w,qint32 h){
    frameWidthResize=w;
    frameHightResize=h;
}
bool configInformation::setX1ResizeCoord(qint32 x,qint32 y){
    if (x>0 && y>0){
        configInformation::X1Resize=x;
        configInformation::Y1Resize=y;
        return true;
    }
    else{
        return false;
    }
}

bool configInformation::setcoefficient(double k ){
    coefficient=k;
}
bool configInformation::setcoefficientResize(double k){
    coefficientResize=k;
}

qint32 configInformation::getframeWidth(){
    return frameWidth;
}
qint32 configInformation::getframeHight(){
    return frameHight;
}
qint32 configInformation::getframeWidthResize(){
    return frameWidthResize;
}
qint32 configInformation::getframeHightResize(){
    return frameHightResize;
}
qint32 configInformation::getX1Resize(){
    return X1Resize;
}
qint32 configInformation::getY1Resize(){
    return Y1Resize;
}

double configInformation::getcoefficient( ){
    return coefficient;
}
double configInformation::getcoefficientResize(){
    return coefficientResize;
}

qint32 configInformation::getdistanceInPixels(){
    return configInformation::distanceInPixels;

}

bool configInformation::setdistanceInPixels(qint32 p){
    if (p>0)
    {
        configInformation::distanceInPixels= p;
        return true;
    }
    else{
        return false;
    }


}

double configInformation::getdistanceInMm(){
    return distanceInMmNow;

}
bool configInformation::setdistanceInMm(double mm){
    if(mm>=distanceInMmMinimum && mm<=distanceInMmMaximum){
        configInformation::distanceInMmNow = mm;
        return true;

    }
    else {
        return false;
    }

}


 bool configInformation::getEnabledResize(){
    return  configInformation::enabledResize;
}

 bool configInformation::setEnabledResize(bool e){
    configInformation::enabledResize = e;
}


QPalette configInformation::getpalleteAllWindows(){
    return palleteAllWindows;
}

bool configInformation::setpalleteAllWindows(QPalette pallete){
    palleteAllWindows=pallete;
    return true;
}

QString configInformation::getnameFile(){
    return  nameFile;
}

bool configInformation::setnameFile(QString name){
    if (name.size()!=0)
    {
         nameFile=name;
         return true;
    }
    else {
        return false;
    }


}

bool configInformation::getrewrite(){
    return rewrite;

}

bool configInformation::setrewrite(bool e)
{
    rewrite = e;
    return true;
}

bool configInformation::getfirstWriteDate(){
    return firstWriteDate;
}

bool configInformation::setfirstWriteDate(bool e){
    firstWriteDate=e;
    return true;

}

QFont configInformation::getfont(){
    return font;
}


bool configInformation::setfont(QFont f){
    font=f;
    return true;
}




qint32 configInformation::sizeWindowCaptureMinimum;
qint32 configInformation::sizeWindowCaptureMaximum;
qint32 configInformation::sizeWindowCaptureNow;

double configInformation::distanceInMmMinimum;
double configInformation::distanceInMmMaximum;


qint32 configInformation::periodCaptureMinimum;
qint32 configInformation::periodCaptureMaximum;
qint32 configInformation::periodCaptureNow;

qint32 configInformation::captureNumber;

qint32 configInformation::frameWidth,configInformation::frameHight;
qint32 configInformation::frameWidthResize,configInformation::frameHightResize;
qint32 configInformation::X1Resize,configInformation::Y1Resize;
double configInformation::coefficient;
double configInformation::coefficientResize;


qint32 configInformation::distanceInPixels;
double configInformation::distanceInMmNow;

bool configInformation::enabledResize;


QPalette configInformation::palleteAllWindows;
QString configInformation::nameFile;
bool configInformation::rewrite;
bool configInformation::firstWriteDate;
QFont configInformation::font;



configInformation::configInformation(QObject *parent) :
    QObject(parent)
{
}
