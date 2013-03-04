#ifndef IMAGECALCULATE_H
#define IMAGECALCULATE_H

#include <QThread>
#include <cv.h>
#include <highgui.h>

#include <iostream>

#include  "canal_contur.h"

class imageCalculate : public QThread
{
    Q_OBJECT
public:
    explicit imageCalculate(QObject *parent = 0);
    explicit imageCalculate(IplImage* in,int* countContours, double *diametr, QObject *parent = 0);
signals:

public slots:
private:
    void run();
    IplImage *src;
    int *countContours;
    double *diametr;

};

#endif // IMAGECALCULATE_H
