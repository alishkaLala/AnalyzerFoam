#ifndef CONVERTER_H
#define CONVERTER_H

#include <QThread>
#include <QImage>

#include <cv.h>
#include <highgui.h>

class Converter : public QThread
{
    Q_OBJECT
public:
    explicit Converter(QObject *parent = 0);
    explicit Converter(IplImage *img,QObject *parent = 0);
signals:

public slots:

private :
    void  run();
    const IplImage * iplImage;
};

#endif // CONVERTER_H
