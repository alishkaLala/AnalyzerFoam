#include "canal_contur.h"

Canal_contur::Canal_contur(QObject *parent) :
        QThread(parent)
{
}


Canal_contur::Canal_contur(const IplImage *in, IplImage *out, int gaus, double threshold1, double threshold2, double k1, double k2,QObject *parent) :
        QThread(parent)
{
        this->in = in;
        this->out=out;
        this->gaus= gaus;
        this->threshold1= threshold1;
        this->threshold2= threshold2;
        this->k1 = k1;
        this->k2= k2;
        this->start();
}

void Canal_contur::run(){
        pr_1 = cvCreateImage( cvGetSize(in), 8, 1 );
        pr_2 = cvCreateImage( cvGetSize(in), 8, 1 );
        normalize(in,pr_1);
        gaus = (gaus/2)? gaus:gaus+1;
        cvSmooth(pr_1,pr_2,CV_GAUSSIAN,gaus,gaus);
        dst = cvCreateImage( cvGetSize(in), IPL_DEPTH_16S, in->nChannels);
        cvLaplace(in, dst, 3); double max = 0;int maxi = in->height,maxj = in->width;
        for(int i=0;i<maxi;i++) for(int j=0;j<maxj;j++) max = (cvGetReal2D( dst, i, j )>max)?cvGetReal2D( dst, i, j ):max;
        threshold2 = (threshold2>0)? threshold2:max*k1;// 0.027;//ini
        threshold1 = (threshold1>0)? threshold1:threshold2*k2;//ini 0.75
        cvCanny(pr_2,out,threshold1,threshold2,3);
        int radius = 1,iterations=1;
        Kern = cvCreateStructuringElementEx(radius*2+1, radius*2+1, radius, radius, CV_SHAPE_ELLIPSE);
        cvDilate(out, out, Kern, iterations);cvErode(out, out, Kern, iterations);

        cvReleaseImage(&pr_1);cvReleaseImage(&pr_2);cvReleaseImage(&dst);
        cvReleaseStructuringElement(&Kern);




}
void Canal_contur::normalize(const IplImage* in, IplImage* out)
{
        double vmin=0,vmax=0;
        cvMinMaxLoc(in, &vmin, &vmax);
        int maxi = in->height,maxj = in->width;
        for(int i=0;i<maxi;i++) for(int j=0;j<maxj;j++) cvSetReal2D(out,i,j,(cvGetReal2D( in, i, j ) - vmin)/(vmax-vmin)*255);
}
