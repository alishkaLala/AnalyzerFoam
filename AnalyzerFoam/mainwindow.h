#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTimer>
#include <QMessageBox>
#include <QEvent>

#include "filewriteread.h"
#include "infoframe.h"
#include "openglgraph.h"
#include "imageprocessing.h"


#include <cv.h>
#include <highgui.h>
#include <settingmainframes.h>
#include <settingcaptureframe.h>


#include <algorithm>
#include <iostream>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void showEvent(QShowEvent *event);
    void closeEvent(QCloseEvent *event);
    explicit MainWindow(QWidget *parent = 0);
      FileWriteRead *tmp ;
    ~MainWindow();
     void showing();

private slots:


    void captureChoised(int);
    void on_pushButton_clicked();

    void on_buttonStart_clicked();
    void on_buttonStop_clicked();



    void captureOff();

    void hideCapture();
    void showCapture();

    void showAboutProgram();
    void showInfoFrame();
    void showSettingFrame();
    void showSettingCapture();
    void showOpenGLGraph();

    void imageGetting( IplImage *img);

    void setSartStopImegeGetting(bool enabled);
    void infoGetting(double count,double diametr);


    void on_pushButton_2_clicked();

public:
     IplImage* tmpImg;


    InfoFrame *infoFrame;
    SettingMainFrames *settingMainFrames;
    SettingCaptureFrame *settingCaptureFrame;
    OpenglGraph *gr ;

    qint8 findCapture();
    Ui::MainWindow *ui;
    QList<QAction*>  menuCaptureArray;
    qint8 numberOfCapture;   // кількість  підключенних камер
    qint32 timeToWork;
    qint32 choisedCaptureNumber;

    CvCapture* capture;
    IplImage* frame;

    uchar* dataToDelete;


// setting for working with capture
    IplImage* resize;
    bool enabledResize;
    qint32 x1Resize,y1Resize;
    qint32 frameWidth,frameHight;
    qint32 frameWidthResize,frameHightResize;
    double coefficient;
    double coefficientResize;

    void readSettingCaprure();

    //QTimer *timerCapture;
    //qint32 timerPeriod;

    void initialMenuCapture();
    void initialConnections();
    void initValues();
    IplImage* QImageToIplImage(const QImage * qImage);
    QImage* IplImageToQImage(const IplImage * iplImage, uchar **data,
                             double mini, double maxi);
    void elemetShow();
    void elementHide();

    void showImage();
    bool showImageJpg;
    void createWindows();
    bool okToContinue(QString Msg);



    ImageProcessing *worker;




};

#endif // MAINWINDOW_H
