#include "infoframe.h"
#include "ui_infoframe.h"

InfoFrame::InfoFrame(QWidget *parent) :
    QWidget(0),
    ui(new Ui::InfoFrame)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hide()));

}

InfoFrame::~InfoFrame()
{
    delete ui;
}
void InfoFrame::destroyThis(){
    destroy();
}
