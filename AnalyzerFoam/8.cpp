
// frame = cvQueryFrame( capture );



frame = cvLoadImage("4.jpg",CV_LOAD_IMAGE_COLOR);
tmpImg=frame;

if (!this->showImageJpg)
        {
                IplImage* resizew;

                if (!ui->processingImageShow->isChecked()){
                        qint32 dx = frame ->width,
                                        dy =frame -> height;
                        // double k = max( ( double )dx / ui->capturePicture->width()), ( double )dy /  ui->capturePicture->height() );
                        double k = ( double )dx / ui->capturePicture->width();
                        dx = ( int )( ( double )dx / k );
                        dy = ( int )( ( double )dy / k );
                        resizew = cvCreateImage(cvSize(dx,dy), IPL_DEPTH_8U, 3);
                        cvResize(frame, resizew,  CV_INTER_NN );
                        frame=resizew;
                        uchar* data = NULL;
                        delete this->dataToDelete;
                        QImage* qt_img = IplImageToQImage(frame, &data, 0.0, 0.0);
                        ui->capturePicture->setPixmap(QPixmap::fromImage(*qt_img));
                        cvReleaseImage( &resizew );
                        cvResetImageROI(frame);
                        delete qt_img;
                        this->dataToDelete= data;
                }


                if (ui->processingImageShow->isChecked())
                        {
                                IplImage* tmpForDelete;
                                this->frame = cvQueryFrame( capture );
                                resize = cvCreateImage(cvSize( this->frameWidth,this->frameHight), IPL_DEPTH_8U, 3);
                                cvResize( frame, resize,  CV_INTER_NN );
                                frame=resize;
                                tmpForDelete = resize;


                                if (this->enabledResize){
                                        cvSetImageROI(this->frame,cvRect
                                                      (this->x1Resize,this->y1Resize,
                                                       this->frameWidthResize,this->frameHightResize) );
                                        resize = cvCreateImage(cvSize(this->frameWidthResize,this->frameHightResize), IPL_DEPTH_8U, 3);
                                        cvResize( frame, resize,  CV_INTER_NN );
                                        frame=resize;
                                }

                                qint32 dx = frame ->width,
                                                dy =frame -> height;

                                double k = ( double )dx / ui->capturePicture->width();
                                dx = ( int )( ( double )dx / k );
                                dy = ( int )( ( double )dy / k );
                                resizew = cvCreateImage(cvSize(dx,dy), IPL_DEPTH_8U, 3);
                                cvResize(frame, resizew,  CV_INTER_NN );
                                frame=resizew;
                                uchar* data = NULL;
                                delete this->dataToDelete;
                                QImage* qt_img = IplImageToQImage(frame, &data, 0.0, 0.0);
                                ui->capturePicture->setPixmap(QPixmap::fromImage(*qt_img));
                                cvReleaseImage( &resizew );
                                cvReleaseImage(&tmpForDelete);
                                cvReleaseImage( &resize );
                                cvResetImageROI(frame);
                                delete qt_img;
                                this->dataToDelete= data;


                        }
        }
cvReleaseImage(&tmpImg);
// cvReleaseImage(&tmp);
