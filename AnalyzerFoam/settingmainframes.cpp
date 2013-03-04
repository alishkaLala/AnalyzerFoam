#include "settingmainframes.h"
#include "ui_settingmainframes.h"

SettingMainFrames::SettingMainFrames(QWidget *parent) :
    QWidget(0),
    ui(new Ui::SettingMainFrames)
{
    ui->setupUi(this);
    this->readSetting();
    this->father = parent;
    this->apply();
    this->setGui();



}
void SettingMainFrames::apply()
{
    this->setPalette(this->palletFrames);
    this->setFont(this->fontFrame);
    this->repaint();

}
void SettingMainFrames::setGui(){
    ui->lineEdit_2->setText(configInformation::getnameFile());
    ui->checkBox->setChecked(configInformation::getrewrite());
    ui->checkBox_2->setChecked(configInformation::getfirstWriteDate());
}

SettingMainFrames::~SettingMainFrames()
{
    delete ui;
}

void SettingMainFrames::readSetting(){
    this->palletFrames=configInformation::getpalleteAllWindows();
    this->fontFrame= configInformation::getfont();
    this->fileName = configInformation::getnameFile();

    }

void SettingMainFrames::writeSetting(){
    configInformation::setpalleteAllWindows(this->palletFrames);
    configInformation::setfont(this->fontFrame);
    configInformation::writeToFile();
    configInformation::setrewrite(ui->checkBox->isChecked());
    configInformation::setfirstWriteDate(ui->checkBox_2->isChecked());
}

void SettingMainFrames::on_pushButton_4_clicked()
{
      QColor ColorFrame = QColorDialog::getColor();
      palletFrames.setColor(QPalette::Base,ColorFrame);
      //this->setBackgroundRole(c);
      this->setPalette(palletFrames);


}





void SettingMainFrames::on_pushButton_5_clicked()
{
    QColor ColorFrame = QColorDialog::getColor();
    palletFrames.setColor(QPalette::WindowText,ColorFrame);
    palletFrames.setColor(QPalette::Text,ColorFrame);
    palletFrames.setColor(QPalette::BrightText,ColorFrame);
    palletFrames.setColor(QPalette::HighlightedText,ColorFrame);
    //c.setColor(QPalette::Background,ColorFrame);
    this->setPalette(palletFrames);

}

void SettingMainFrames::on_pushButton_6_clicked()
{
    QColor ColorFrame = QColorDialog::getColor();
    palletFrames.setColor(QPalette::Background,ColorFrame);
    this->setPalette(palletFrames);

}

void SettingMainFrames::on_pushButton_7_clicked()
{
    QColor ColorFrame = QColorDialog::getColor();
    palletFrames.setColor(QPalette::Button,ColorFrame);
    this->setPalette(palletFrames);
}

void SettingMainFrames::on_pushButton_8_clicked()
{
    QColor ColorFrame = QColorDialog::getColor();
    palletFrames.setColor(QPalette::ButtonText,ColorFrame);
    this->setPalette(palletFrames);
}



void SettingMainFrames::on_pushButton_9_clicked()// ????????????????????????????????????????????????????????
{

    this->palletFrames=QWidget::palette();
    this->fontFrame=QWidget::font();

    this->setPalette(this->palletFrames);
    this->setFont(this->fontFrame);
    this->repaint();

}

void SettingMainFrames::on_pushButton_3_clicked()
{
    this->fileName=QFileDialog::getOpenFileName(this,tr("Open"));
    ui->lineEdit_2->setText(this->fileName);

}

void SettingMainFrames::on_pushButton_10_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if (ok)
    {
        this->fontFrame = font;
        this->setFont(font);
        this->repaint();
    }
}
void SettingMainFrames::on_pushButton_11_clicked()
{

    this->fileName=QFileDialog::getSaveFileName(this,tr("Create"),tr(""));
    ui->lineEdit_2->setText(this->fileName);
}

void SettingMainFrames::on_SaveSetting_clicked()
{
    if (ui->lineEdit_2->text().trimmed()!="")
    {
        this->writeSetting();
        this->close();
    }
    else
    {
        QMessageBox::information(this,"Error","File name not defined",QMessageBox::Ok);

    }


}
void SettingMainFrames::on_CanselSetting_clicked()
{
     this->close();
}

void SettingMainFrames::closeEvent(QCloseEvent *event=NULL){
     this->hide();

    this->father->show();
    this->father->setVisible(true);

}

void SettingMainFrames::on_Standart_clicked()
{
    this->palletFrames = QApplication::palette();
    this->fontFrame = QApplication::font();
    this->apply();

}
