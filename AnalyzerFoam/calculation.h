#ifndef CALCULATION_H
#define CALCULATION_H

#include <QThread >
#include <cv.h>
#include <highgui.h>

class Calculation : public QThread 
{

public:
  static  IplImage *startimg;

    void run ();
};

#endif // CALCULATION_H
