#include "imagecalculate.h"

imageCalculate::imageCalculate(QObject *parent) :
    QThread(parent)
{
}
  imageCalculate::imageCalculate( IplImage* in,int* countContours, double *diametr,QObject *parent ):
        QThread(parent)
  {
      this->src = in;
      this->countContours= countContours;
      this->diametr = diametr;
      this->start();

  }
void imageCalculate::run(){


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
                  *countContours++;

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

                  *diametr +=size.width+size.height;


                  cvReleaseMat(&points_f);

          }

*/

    //cvClearSeq(contours);
   // cvReleaseMemStorage(&storage);
   // cvReleaseStructuringElement(&Kern);


    cvReleaseImage(&src);
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
    delete  pr3;

}
