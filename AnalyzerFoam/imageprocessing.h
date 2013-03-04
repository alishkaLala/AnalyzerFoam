#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QThread>
#include <QMessageBox>
#include <QDebug>


#include <cv.h>
#include <highgui.h>

#include <iostream>


#include "canal_contur.h"
class ImageProcessing : public QThread
{
    Q_OBJECT
    void run ();
public:
    explicit ImageProcessing(QObject *parent = 0);

    void setChoisedCpture(int value);

signals:
    void test();
    void imageIsReady( IplImage *img);
    void imageCalculateReady( IplImage *img);
    void infoIsReady(double count, double diametr);

public slots:

    void working(bool);
    void getImage();
    void setCalculation(bool);
private:
    bool isWorking;
    bool calculateImage;
    unsigned long int  kadrProssesd;
    int choisedCapture;
    double k1,k2;

};

#endif // IMAGEPROCESSING_H
