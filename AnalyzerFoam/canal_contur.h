#ifndef CANAL_CONTUR_H
#define CANAL_CONTUR_H

#include <QThread>
#include <QMessageBox>
#include <QDebug>


#include <cv.h>
#include <highgui.h>
class Canal_contur : public QThread
{
    Q_OBJECT
public:
    explicit Canal_contur(QObject *parent = 0);
    explicit Canal_contur(const IplImage* in, IplImage* out,int gaus, double threshold1=0, double threshold2=0,double k1= 0.027, double k2=0.75,QObject *parent = 0);

signals:

public slots:


private:
    void run();
    void normalize(const IplImage* in, IplImage* out);

    IplImage* pr_1;
    IplImage* pr_2;
    const  IplImage *in;
    IplImage *out;
    int gaus; double threshold1; double threshold2;
    IplImage* dst;
    IplConvKernel* Kern;

    double k1,k2;
};

#endif // CANAL_CONTUR_H
