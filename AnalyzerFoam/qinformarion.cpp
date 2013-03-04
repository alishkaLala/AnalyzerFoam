#include "qinformarion.h"
#include <QSharedData>

class QInformarionData : public QSharedData {
public:
};

QInformarion::QInformarion() : data(new QInformarionData)
{
}

QInformarion::QInformarion(const QInformarion &rhs) : data(rhs.data)
{
}

QInformarion &QInformarion::operator=(const QInformarion &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

QInformarion::~QInformarion()
{
}
