#ifndef INFOFRAME_H
#define INFOFRAME_H

#include <QWidget>

namespace Ui {
    class InfoFrame;
}

class InfoFrame : public QWidget
{
    Q_OBJECT

public:
    explicit InfoFrame(QWidget *parent = 0);
    void destroyThis();
    ~InfoFrame();

private:
    Ui::InfoFrame *ui;
};

#endif // INFOFRAME_H
