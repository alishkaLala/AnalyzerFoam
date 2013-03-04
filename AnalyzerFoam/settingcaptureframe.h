#ifndef SETTINGCAPTUREFRAME_H
#define SETTINGCAPTUREFRAME_H

#include <QWidget>
#include <QTimer>
#include <QDoubleValidator>
#include <QToolTip>
#include <QMessageBox>
#include <QCloseEvent>
#include <QApplication>
#include <QDebug>

#include <iostream>
#include<cmath>

#include <cv.h>
#include <highgui.h>


#include <configinformation.h>
#include <imageprocessing.h>

namespace Ui {
    class SettingCaptureFrame;
}

class SettingCaptureFrame : public QWidget
{
    Q_OBJECT

public:

    void startWork();
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);

    explicit SettingCaptureFrame(ImageProcessing *worker, QWidget *parent = 0);
    ~SettingCaptureFrame();



    QWidget  *father;
    ImageProcessing *worker;


private:
    bool isStartResize();
    static SettingCaptureFrame *obj;

    static void myMouseCallback( int event, int x, int y, int flags, void* param);
    void myMouseCallbackDelegated( int event, int x, int y, int flags, void* param);

    //Working with resizing and setting mm
    bool calculateDistanceInPixels();
    bool applyResize();
    void calculateResize();
    qint32 frameWidth,frameHight;
    qint32 frameWidthResize,frameHightResize;
    double coefficient;
    double coefficientResize;



    qint32 distanceInPixels;
    double distanceInMM;


    IplImage *standard;
    //coordinate points
    qint32 x1,y1,x2,y2;
    qint32 X1,Y1;
    qint32 X2,Y2;
    qint32 x1Resize,x2Resize,y1Resize,y2Resize;
    void clearCoords();
    void clearResize();
    bool checkCoords();

    Ui::SettingCaptureFrame *ui;
//init

    void initialize();
    void initSetting();
    void initialConnections();
    void timerStart();
    void timerStop();

    void startingResize();
    void startingCalculateDistance();
    void hideBoxes();
    void showBoxes();

    void readSetting();
    void writeSetting();
    void backSetting();

    void hideAllBoxes();





    QTimer *timerCapture;
    qint32 timerPeriod;
    QString nameCaptureFrame;

    bool startResize;
    bool startCalculateDistance;
    bool enabledResize;



     IplImage* frame;
    IplImage* resize;
    qint32 captureNumber;


    CvCapture* capture;




private slots:
    void stopWork();

    void toolTipMm();
    void validMmAndSet();
    void timerEvent_showCapture();
    void on_defRect_clicked();



    void calculateCaptureSizeFrame(int w);
    void on_defDistInPixels_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButtonNo_clicked();
    void on_pushButtonOk_clicked();

    void on_SettingCansel_clicked();
    void on_SettingStandart_clicked();

    void on_SettingApply_clicked();
    void on_pushButtonStart_clicked();
    void setValueShowing(bool);
    void imageCalculatingGetting(IplImage *img);
public slots:
      void imageGetting(IplImage *img);

};

#endif // SETTINGCAPTUREFRAME_H
