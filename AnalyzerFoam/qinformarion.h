#ifndef QINFORMARION_H
#define QINFORMARION_H

#include <QSharedDataPointer>

class QInformarionData;

class QInformarion
{
public:
    QInformarion();
    QInformarion(const QInformarion &);
    QInformarion &operator=(const QInformarion &);
    ~QInformarion();

private:
    QSharedDataPointer<QInformarionData> data;
};

#endif // QINFORMARION_H
