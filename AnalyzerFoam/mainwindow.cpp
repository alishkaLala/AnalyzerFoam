#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{

        ui->setupUi(this);

        this->initValues();

        this->initialConnections();
        this->elementHide();



        worker->start();
        this->createWindows();
        connect (ui->pushButton,SIGNAL(clicked()),this->worker,   SLOT(getImage()));


        connect(this->worker,SIGNAL(infoIsReady(double,double)),this,SLOT(infoGetting(double,double)));


        //this->menuAbout->addAction("&About QT",this,SLOT (this->aboutProgram()));
}

void MainWindow::showEvent(QShowEvent *event){
        this->setPalette(configInformation::getpalleteAllWindows());
        this->setFont(configInformation::getfont());
        this->repaint();
        this->readSettingCaprure();

        if(ui->processingImageShow->isChecked ())
                {
                        this->setSartStopImegeGetting (true);
                }

}

void MainWindow::closeEvent(QCloseEvent *event= NULL){
        this->worker->working(false);

}
void MainWindow::readSettingCaprure(){
        this->enabledResize = configInformation::getEnabledResize();
        this->x1Resize=configInformation::getX1Resize();
        this->y1Resize=configInformation::getY1Resize();
        this->frameWidth=configInformation::getframeWidth();
        this->frameHight=configInformation::getframeHight();
        this->frameWidthResize=configInformation::getframeWidthResize();
        this->frameHightResize=configInformation::getframeHightResize();
        this->coefficient = configInformation::getcoefficient();
        this->coefficientResize = configInformation::getcoefficientResize();
        this->choisedCaptureNumber = 0; // ini read !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
// init
void MainWindow::initialMenuCapture()
{
        this->numberOfCapture = this->findCapture();
        this->ui->menuChoise_capture->clear();

        for (int i=0 ;i<this->numberOfCapture;i++){
                this->menuCaptureArray.append( new QAction (QString::number(i+1), this->ui->menuChoise_capture));
                connect (this->menuCaptureArray[i],SIGNAL(triggered()),SLOT (captureChoised(i)));

        }

        ui->menuChoise_capture->addActions(this->menuCaptureArray);

}
void MainWindow::initialConnections()
{

        connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));
        connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->spinBox,SLOT(setValue(int)));
        connect(ui->actionDisable_capture,SIGNAL(triggered()),this,SLOT (captureOff()));
        connect(ui->actionHide_capture,SIGNAL(triggered()),this,SLOT(hideCapture()));
        connect(ui->actionShow_capture,SIGNAL(triggered()),this,SLOT(showCapture()));
        connect(ui->actionInformation,SIGNAL(triggered()),this,SLOT(showInfoFrame()));
        connect(ui->actionConfiguration_of_program,SIGNAL(triggered()),this ,SLOT(showSettingFrame()));
        connect(ui->actionConfiguration_of_capture,SIGNAL(triggered()),this,SLOT(showSettingCapture()));
        //connect (this->timerCapture, SIGNAL ( timeout () ), SLOT ( timerEvent_showCapture ( ) ) );
        connect (ui->actionTo_graphik,SIGNAL(triggered()),SLOT (showOpenGLGraph()));
        connect( ui->processingImageShow,SIGNAL(toggled(bool)),this,SLOT(setSartStopImegeGetting(bool)));






}
void MainWindow::createWindows(){
        this-> gr = new OpenglGraph(this->worker);
        this->infoFrame=new InfoFrame(this);
        this->settingMainFrames = new SettingMainFrames(this);
        this->settingCaptureFrame = new SettingCaptureFrame(this->worker, this);
}
void MainWindow::initValues()
{
        this->worker = new ImageProcessing();
        this->timeToWork = 100;
        //this->timerPeriod = 100;
        ui->spinBox->setRange(1,this->timeToWork);
        ui->horizontalSlider->setRange(1,this->timeToWork);
        this->initialMenuCapture();
        //this->timerCapture = new QTimer(this);
        this->showImage();




}


// menu capture
void MainWindow::captureOff()
{
        this->worker->working (false);
}
void MainWindow::captureChoised(int value)
{
        worker->setChoisedCpture (value);
        qDebug ()<<value;

}


void MainWindow::on_pushButton_clicked()
{
        this->worker->working(true);
}
bool MainWindow::okToContinue(QString Msg){
        qint32 answer = QMessageBox::warning(this,tr("Увага!"),Msg.toLocal8Bit().constData(),
                                             QMessageBox::Yes,QMessageBox::No);
        if (answer== QMessageBox::Yes) return true;
        return false;
}

//start/stop analiz.
void MainWindow::on_buttonStart_clicked()
{

        if (this->okToContinue(tr("Ви впевнені, що хочете розпочати аналіз?")))
                {
                        ui->menuSetting->setEnabled(false);
                        ui->menuCapture->setEnabled(false);
                        ui->checkBox->setEnabled(false);
                        ui->spinBox->setEnabled (false);

                }


}
void MainWindow::on_buttonStop_clicked()
{

        if (this->okToContinue(tr("Ви впевнені, що хочете завершити аналіз?")))
                {
                        ui->menuSetting->setEnabled(true);
                        ui->menuCapture->setEnabled(true);
                        ui->checkBox->setEnabled(true);
                        ui->spinBox->setEnabled (true);

                }

}


void MainWindow::imageGetting(IplImage *img)
{
        uchar* data = NULL;
        delete this->dataToDelete;
        QImage* qt_img = IplImageToQImage(img, &data, 0.0, 0.0);
        ui->capturePicture->setPixmap(QPixmap::fromImage(*qt_img));
        delete qt_img;
        this->dataToDelete= data;


}
void MainWindow::infoGetting(double count, double diametr){

        if (gr->isVisible ())
                {
                        this->gr->genCoords(count,diametr);
                }

}

//first hide/show element
void MainWindow::elementHide()
{



        // ui->menuExport->setEnabled(false);
}
void MainWindow::elemetShow(){
        ui->menuExport->setVisible(true);
}

//timer + show on frame
qint8 MainWindow::findCapture(){
        CvCapture *cap_temp;
        int   tmpNumberOfCapture  =0;
        while (1)
                {
                        cap_temp=cvCreateCameraCapture(tmpNumberOfCapture++);
                        if (cap_temp==NULL) break;
                        cvReleaseCapture(&cap_temp);
                }
        tmpNumberOfCapture--;
        return tmpNumberOfCapture;
}
void MainWindow::setSartStopImegeGetting(bool enabled)
{
        if (enabled){
                qDebug ()<<"get";
                connect(this->worker,SIGNAL(imageIsReady(IplImage*)),this,SLOT(imageGetting(IplImage*)));

        }
        else {
                disconnect(this->worker,SIGNAL(imageIsReady( IplImage*)),this,SLOT(imageGetting( IplImage*)));
                this->showImage();
        }
}

void MainWindow::showCapture()// ????????????????????????
{
        this->showImageJpg=false;
}
void MainWindow::hideCapture()
{
        this->showImageJpg= true;
        this->showImage();
}
void MainWindow::showImage(){
        ui->capturePicture->setPixmap(QPixmap(":/image/4x.jpg"));


}

//frames
void MainWindow::showAboutProgram()
{

}
void MainWindow::showInfoFrame(){
        this->infoFrame->show();
        this->close();
}
void MainWindow::showSettingFrame(){
        this->settingMainFrames->show();
        this->close();

}
void MainWindow::showSettingCapture(){

        this->close();

        this->setSartStopImegeGetting(false);
        disconnect(this->worker,SIGNAL(imageIsReady( IplImage*)),this,SLOT(imageGetting( IplImage*)));



        this->settingCaptureFrame->show();
        this->worker->working (true);

}
void MainWindow::showOpenGLGraph(){

        gr->setWindowTitle("3d");
        gr->show();

}

void MainWindow::showing()
{

        this->show();
}


MainWindow::~MainWindow()
{
        this->infoFrame->destroyThis();
        this->setSartStopImegeGetting(false);
        this->worker->working (false);
        //delete frame;
        delete ui;
}

// aditional function

IplImage* MainWindow::QImageToIplImage(const QImage * qImage)
{
        int width = qImage->width();
        int height = qImage->height();
        CvSize Size;
        Size.height = height;
        Size.width = width;
        IplImage *charIplImageBuffer = cvCreateImage(Size, IPL_DEPTH_8U, 1);
        char *charTemp = (char *) charIplImageBuffer->imageData;

        for (int y = 0; y < height; y++)
                {
                        for (int x = 0; x < width; x++)
                                {
                                        int index = y * width + x;
                                        charTemp[index] = (char) qGray(qImage->pixel(x, y));
                                }
                }
        return charIplImageBuffer;
}
QImage* MainWindow::IplImageToQImage(const IplImage * iplImage, uchar **data,
                                     double mini, double maxi)
{
        uchar *qImageBuffer = NULL;
        int width = iplImage->width;

        // Note here that OpenCV image is stored so that each lined is
        // 32-bits aligned thus * explaining the necessity to "skip"
        // the few last bytes of each line of OpenCV image buffer.
        int widthStep = iplImage->widthStep;
        int height = iplImage->height;

        switch (iplImage->depth)
                {
        case IPL_DEPTH_8U:
                        if (iplImage->nChannels == 1)
                                {
                                        // IplImage is stored with one byte grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const uchar *iplImagePtr = (const uchar *)iplImage->imageData;
                                        for (int y = 0; y < height; y++)
                                                {
                                                        // Copy line by line
                                                        memcpy(QImagePtr, iplImagePtr, width);
                                                        QImagePtr += width;
                                                        iplImagePtr += widthStep;
                                                }
                                }
                        else if (iplImage->nChannels == 3)
                                {
                                        // IplImage is stored with 3 byte color pixels (3 channels).
                                        // We convert it to a 32 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*4*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const uchar *iplImagePtr = (const uchar *) iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        // We cannot help but copy manually.
                                                                        QImagePtr[0] = iplImagePtr[0];
                                                                        QImagePtr[1] = iplImagePtr[1];
                                                                        QImagePtr[2] = iplImagePtr[2];
                                                                        QImagePtr[3] = 0;

                                                                        QImagePtr += 4;
                                                                        iplImagePtr += 3;
                                                                }
                                                        iplImagePtr += widthStep-3*width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=8U and %d channels\n", iplImage->nChannels);
                                }
                        break;

                case IPL_DEPTH_16U:
                        if (iplImage->nChannels == 1)
                                {
                                        // IplImage is stored with 2 bytes grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const uint16_t *iplImagePtr = (const uint16_t *)iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        // We take only the highest part of the 16 bit value.
                                                                        // It is similar to dividing by 256.
                                                                        *QImagePtr++ = ((*iplImagePtr++) >> 8);
                                                                }
                                                        iplImagePtr += widthStep/sizeof(uint16_t)-width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=16U and %d channels\n", iplImage->nChannels);
                                }
                        break;

                case IPL_DEPTH_32F:
                        if (iplImage->nChannels == 1)
                                {
                                        // IplImage is stored with float (4 bytes) grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const float *iplImagePtr = (const float *) iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        uchar p;
                                                                        float pf = 255 * ((*iplImagePtr++) - mini) / (maxi - mini);

                                                                        if (pf < 0) p = 0;
                                                                        else if (pf > 255) p = 255;
                                                                        else p = (uchar) pf;

                                                                        *QImagePtr++ = p;
                                                                }
                                                        iplImagePtr += widthStep/sizeof(float)-width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=32F and %d channels\n", iplImage->nChannels);
                                }
                        break;

                case IPL_DEPTH_64F:
                        if (iplImage->nChannels == 1)
                                {
                                        // OpenCV image is stored with double (8 bytes) grey pixel.
                                        // We convert it to an 8 bit depth QImage.
                                        qImageBuffer = (uchar *) malloc(width*height*sizeof(uchar));
                                        uchar *QImagePtr = qImageBuffer;
                                        const double *iplImagePtr = (const double *) iplImage->imageData;

                                        for (int y = 0; y < height; y++)
                                                {
                                                        for (int x = 0; x < width; x++)
                                                                {
                                                                        uchar p;
                                                                        double pf = 255 * ((*iplImagePtr++) - mini) / (maxi - mini);

                                                                        if (pf < 0) p = 0;
                                                                        else if (pf > 255) p = 255;
                                                                        else p = (uchar) pf;

                                                                        *QImagePtr++ = p;
                                                                }
                                                        iplImagePtr += widthStep/sizeof(double)-width;
                                                }
                                }
                        else
                                {
                                        qDebug("IplImageToQImage: image format is not supported:\
                                               depth=64F and %d channels\n", iplImage->nChannels);
                                }
                        break;

                default:
                        qDebug("IplImageToQImage: image format is not supported: depth=%d\
                               and %d channels\n", iplImage->depth, iplImage->nChannels);
                }

        QImage *qImage;
        if (iplImage->nChannels == 1)
                {
                        QVector<QRgb> colorTable;
                        for (int i = 0; i < 256; i++)
                                {
                                        colorTable.push_back(qRgb(i, i, i));
                                }
                        qImage = new QImage(qImageBuffer, width, height, QImage::Format_Indexed8);
                        qImage->setColorTable(colorTable);
                }
        else
                {
                        qImage = new QImage(qImageBuffer, width, height, QImage::Format_RGB32);
                }
        *data = qImageBuffer;

        return qImage;
}


void MainWindow::on_pushButton_2_clicked()
{
        this->worker->working(false);
}
