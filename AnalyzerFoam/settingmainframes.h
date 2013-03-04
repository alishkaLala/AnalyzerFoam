#ifndef SETTINGMAINFRAMES_H
#define SETTINGMAINFRAMES_H

#include <QWidget>
#include <QtGui>

#include <configinformation.h>
namespace Ui {
    class SettingMainFrames;
}

class SettingMainFrames : public QWidget
{
    Q_OBJECT

public:


    QFont fontFrame;
    QPalette palletFrames;
    QString fileName;

    explicit SettingMainFrames(QWidget *parent = 0);
    ~SettingMainFrames();
    void closeEvent(QCloseEvent *event);
    QWidget  *father;

private:
    void readSetting();
    void writeSetting();
    void apply();
    void setGui();
private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();



    void on_SaveSetting_clicked();

    void on_CanselSetting_clicked();



    void on_Standart_clicked();

private:
    Ui::SettingMainFrames *ui;
};

#endif // SETTINGMAINFRAMES_H
