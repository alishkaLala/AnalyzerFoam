#include "imageprocessing.h"

ImageProcessing::ImageProcessing(QObject *parent) :
        QThread(parent)
{

        // emit test();
        this->choisedCapture= 0;
        this->isWorking=false;
        this->calculateImage= false;
        this->kadrProssesd = 0;

}

void normalize(const IplImage* in, IplImage* out)
{
        double vmin=0,vmax=0;
        cvMinMaxLoc(in, &vmin, &vmax);
        int maxi = in->height,maxj = in->width;
        for(int i=0;i<maxi;i++) for(int j=0;j<maxj;j++) cvSetReal2D(out,i,j,(cvGetReal2D( in, i, j ) - vmin)/(vmax-vmin)*255);
}

void canal_contur(const IplImage* in, IplImage* out,int gaus, double threshold1=0, double threshold2=0)
{   IplImage* pr_1 = cvCreateImage( cvGetSize(in), 8, 1 );
        IplImage* pr_2 = cvCreateImage( cvGetSize(in), 8, 1 );
        normalize(in,pr_1);
        gaus = (gaus/2)? gaus:gaus+1;
        cvSmooth(pr_1,pr_2,CV_GAUSSIAN,gaus,gaus);

        IplImage* dst = cvCreateImage( cvGetSize(in), IPL_DEPTH_16S, in->nChannels);
        cvLaplace(in, dst, 3); double max = 0;int maxi = in->height,maxj = in->width;
        for(int i=0;i<maxi;i++) for(int j=0;j<maxj;j++) max = (cvGetReal2D( dst, i, j )>max)?cvGetReal2D( dst, i, j ):max;
        threshold2 = (threshold2>0)? threshold2:max*0.027;//ini
        threshold1 = (threshold1>0)? threshold1:threshold2*0.75;//ini
        cvCanny(pr_2,out,threshold1,threshold2,3);
        int radius = 1,iterations=1;
        IplConvKernel* Kern = cvCreateStructuringElementEx(radius*2+1, radius*2+1, radius, radius, CV_SHAPE_ELLIPSE);
        cvDilate(out, out, Kern, iterations);cvErode(out, out, Kern, iterations);
        cvReleaseImage(&pr_1);cvReleaseImage(&pr_2);cvReleaseImage(&dst);
        cvReleaseStructuringElement(&Kern);
}

void ImageProcessing::setCalculation (bool value)
{
        this->calculateImage= value;
        this->kadrProssesd = 0;
}
void ImageProcessing::setChoisedCpture (int value)
{
        this->choisedCapture =  value;
}
void ImageProcessing::run()
{
        exec();
}
void ImageProcessing::getImage()
{
        int number = this->choisedCapture;
        CvCapture* capture =0;
        IplImage* frame =0;
        char filename[512];
        capture = cvCreateCameraCapture(number);
        assert(capture);
        cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);
        frame = cvLoadImage("4.jpg",CV_LOAD_IMAGE_COLOR);
        int x = 389,y = 292;//2592*1944 ->389*292
        while(isWorking){
                frame = cvQueryFrame( capture );
                //frame = cvLoadImage("4.jpg",CV_LOAD_IMAGE_COLOR);
                IplImage *src = cvCreateImage(cvSize(x,y),frame->depth,frame->nChannels);

                //  cvResize(frame,src,CV_INTER_LINEAR);
                cvShowImage("capture", frame);
                emit imageIsReady(frame);
                emit infoIsReady (qrand ()%40,qrand ()%40);


                cvWaitKey(3);
                cvReleaseImage(&src);


        }


        cvReleaseCapture(&capture);
        cvReleaseImage(&frame);

}
void ImageProcessing::working(bool setting){

        this->isWorking = setting;
        qDebug ()<<"getValue"<<setting;
}
