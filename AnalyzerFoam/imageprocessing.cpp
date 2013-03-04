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

                cvResize(frame,src,CV_INTER_LINEAR);
                cvShowImage("capture", src);

                if (true)
                        {
                                    IplImage* hsv = cvCreateImage( cvGetSize(src), 8, 3 );// зображення в форматі HSV
                                    IplImage* h_plane = cvCreateImage( cvGetSize(src), 8, 1 );// канал H
                                    IplImage* s_plane = cvCreateImage( cvGetSize(src), 8, 1 );// канал S
                                    IplImage* v_plane = cvCreateImage( cvGetSize(src), 8, 1 );// канал V

                                    IplImage* h_can = cvCreateImage( cvGetSize(src), 8, 1 ); // пікселі границ
                                    IplImage* s_can = cvCreateImage( cvGetSize(src), 8, 1 ); // пікселі границ
                                    IplImage* v_can = cvCreateImage( cvGetSize(src), 8, 1 ); // пікселі границ

                                    IplImage* sum_can;// = cvCreateImage( cvGetSize(src), 8, 1 ); // пікселі границ
                                    Canal_contur *pr1,*pr2,*pr3;

                                    int b=0,a=0;
                                    cvCvtPixToPlane( src, h_plane, s_plane, v_plane, 0 ); //RGB  канали




                            pr1 = new Canal_contur(v_plane,v_can,11,a,b);//запускати окремими потоками
                                    pr2 = new Canal_contur(h_plane,h_can,11,a,b);//запускати окремими потоками
                                    pr3 = new Canal_contur(s_plane,s_can,11,a,b);//запускати окремими потоками
                                    cvShowImage("6canny_r",v_can);    cvShowImage("6canny_g",h_can);    cvShowImage("6canny_b",s_can);
                                    pr1->wait();
                                    pr2->wait();
                                    pr3->wait();

                                    sum_can=v_can;

                                    cvOr(sum_can,v_can,sum_can);
                                    cvOr(sum_can,h_can,sum_can);
                                    cvOr(sum_can,s_can,sum_can);




                                   CvMemStorage* storage = cvCreateMemStorage(0);
                                    CvSeq* contours=0;

                                    cvFindContours( sum_can, storage,&contours,sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));
                                     //зображення контурів
                                    for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
                                                  int count = seq0->total; if( count < 10 ) continue;
                                                  cvDrawContours(sum_can, seq0, cvScalar(255), cvScalar(255), 0, CV_FILLED, 8); // рисуем контур
                                          }

                                    cvShowImage("summa_x",sum_can);

                                    int radius = 1,iterations=1;
                                      IplConvKernel* Kern = cvCreateStructuringElementEx(radius*2+1, radius*2+1, radius, radius, CV_SHAPE_ELLIPSE);

                                      cvErode(sum_can, sum_can, Kern, iterations);
                                      cvDilate(sum_can, sum_can, Kern, iterations);

                                    cvReleaseMemStorage(&storage);
                                    cvClearSeq(contours);

                                    storage = cvCreateMemStorage(0); contours=0;

                                    cvFindContours( sum_can, storage,&contours,sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE,cvPoint(0,0));


                                    //зображення контурів


                                  for(CvSeq* seq0 = contours;seq0!=0;seq0 = seq0->h_next){
                                                int count = seq0->total;
                                                  CvPoint center;CvSize size;CvBox2D box;
                                                  if( count < 10 ) continue;


                                                  CvMat* points_f = cvCreateMat( 1, count, CV_32FC2 );
                                                  CvMat points_i = cvMat( 1, count, CV_32SC2, points_f->data.ptr );
                                                  cvCvtSeqToArray( seq0, points_f->data.ptr, CV_WHOLE_SEQ );
                                                  cvConvert( &points_i, points_f );
                                                   box = cvFitEllipse2( points_f );

                                                  center = cvPointFrom32f(box.center);
                                                  size.width = cvRound(box.size.width*0.5);
                                                  size.height = cvRound(box.size.height*0.5);


                                                   cvEllipse(src, center, size,-box.angle, 0, 360,CV_RGB(0,0,255), -1, CV_AA, 0);
                                                  //cvDrawContours(src, seq0, CV_RGB(0,0,0), CV_RGB(0,0,250), 0, CV_FILLED, 8); // рисуем контур
                                                   //cvCircle(src,center,(size.width+size.height)/2,CV_RGB(0,0,255),1, CV_AA, 0);

                                                //  *diametr +=size.width+size.height;


                                                //  cvReleaseMat(&points_f);

                                          }




                                    //cvClearSeq(contours);
                                   // cvReleaseMemStorage(&storage);
                                   // cvReleaseStructuringElement(&Kern);


                                //    cvReleaseImage(&src);
                                    cvReleaseImage( &hsv);




                                    cvReleaseImage(&h_plane );// канал H
                                    cvReleaseImage(&s_plane );// канал S
                                    cvReleaseImage(&v_plane);// канал V


                                    cvReleaseImage(&sum_can ); // пікселі границ
                                    cvReleaseImage( &h_can); // пікселі границ
                                    cvReleaseImage(&s_can ); // пікселі границ
                                    cvReleaseImage(&v_can); // пікселі границ



                                    delete  pr1;
                                    delete  pr2;
                                    delete  pr3;    /**/

                        }
                emit imageIsReady(src);

                emit infoIsReady (qrand ()%40,qrand ()%40);


                cvWaitKey(1000);
                //cvReleaseImage(&src);


        }


        cvReleaseCapture(&capture);
        cvReleaseImage(&frame);

}
void ImageProcessing::working(bool setting){

        this->isWorking = setting;
        qDebug ()<<"getValue"<<setting;
}
