#ifndef CONFIGINFORMATION_H
#define CONFIGINFORMATION_H

#include <QObject>
#include <QPalette>
#include <QFont>
#include <QApplication>
#include <QSettings>



class configInformation : public QObject
{
    Q_OBJECT
public:
    static QSettings *file;

    static void setStandardPreference();
    static void setStandardPreferenceCapture();
    static bool initialize(QString a);
    static bool writeToFile();
    static bool readFromFile();


    explicit configInformation(QObject *parent = 0);


    static bool setSizeWindowCapture(qint32 size);
    static qint32 getSizeWindowCapture();

    static bool setdistanceInMm(double mm);
    static double getdistanceInMm();

    static bool setperiodCapture(qint32 size);
    static qint32 getperiodCapture();


    static qint32 getCaptureNumber();
    static bool setCaptureNumber(qint32 N);

    static bool setframeWidthAndFrameHight(qint32 w,qint32 h);
    static bool setframeWidthResizeAndframeHightResize(qint32 w,qint32 h);
    static bool setX1ResizeCoord(qint32 x,qint32 y);
    static bool setcoefficient(double k );
    static bool setcoefficientResize(double k);

    static qint32 getframeWidth();
    static qint32 getframeHight();
    static qint32 getframeWidthResize();
    static qint32 getframeHightResize();
    static qint32 getX1Resize();
    static qint32 getY1Resize();


    static double getcoefficient();
    static double getcoefficientResize();

    static qint32 getdistanceInPixels();
    static bool setdistanceInPixels(qint32 p);


    static bool getEnabledResize();
    static bool setEnabledResize(bool e);


    static QPalette getpalleteAllWindows();
    static bool setpalleteAllWindows(QPalette pallete);

    static QString getnameFile();
    static bool setnameFile(QString name);


    static bool getrewrite();
    static bool setrewrite(bool e);


    static bool getfirstWriteDate();
    static bool setfirstWriteDate(bool e);

    static QFont getfont();
    static bool setfont(QFont f);



private:


    static qint32 sizeWindowCaptureMinimum;
    static qint32 sizeWindowCaptureMaximum;
    static qint32 sizeWindowCaptureNow;

    static double distanceInMmMinimum;
    static double distanceInMmMaximum;
    static double distanceInMmNow;

    static qint32 periodCaptureMinimum;
    static qint32 periodCaptureMaximum;
    static qint32 periodCaptureNow;

    static qint32 captureNumber;

    static qint32 frameWidth,frameHight;
    static qint32 frameWidthResize,frameHightResize;
    static qint32 X1Resize,Y1Resize;
    static double coefficient;
    static double coefficientResize;


    static qint32 distanceInPixels;

    static bool enabledResize;

    static QPalette palleteAllWindows;
    static QString nameFile;
    static bool rewrite;
    static bool firstWriteDate;
    static QFont font;












};

#endif // CONFIGINFORMATION_H
