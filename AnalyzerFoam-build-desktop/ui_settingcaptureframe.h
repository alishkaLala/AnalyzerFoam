/********************************************************************************
** Form generated from reading UI file 'settingcaptureframe.ui'
**
** Created: Tue 5. Mar 01:38:40 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGCAPTUREFRAME_H
#define UI_SETTINGCAPTUREFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingCaptureFrame
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QSpinBox *spinBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *defRect;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout;
    QLabel *labelX1;
    QLabel *labelY1;
    QLabel *labelY2;
    QLabel *labelX2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *defDistInPixels;
    QLabel *label_4;
    QLabel *pixels;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *widthCaptureWindow;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonStart;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SettingApply;
    QPushButton *SettingCansel;
    QPushButton *SettingStandart;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_6;

    void setupUi(QWidget *SettingCaptureFrame)
    {
        if (SettingCaptureFrame->objectName().isEmpty())
            SettingCaptureFrame->setObjectName(QString::fromUtf8("SettingCaptureFrame"));
        SettingCaptureFrame->resize(270, 659);
        gridLayout_4 = new QGridLayout(SettingCaptureFrame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_5 = new QGroupBox(SettingCaptureFrame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout_3->addWidget(spinBox, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox = new QGroupBox(SettingCaptureFrame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        defRect = new QPushButton(groupBox);
        defRect->setObjectName(QString::fromUtf8("defRect"));

        verticalLayout->addWidget(defRect);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(SettingCaptureFrame);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout = new QGridLayout(groupBox_6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelX1 = new QLabel(groupBox_6);
        labelX1->setObjectName(QString::fromUtf8("labelX1"));

        gridLayout->addWidget(labelX1, 0, 0, 1, 1);

        labelY1 = new QLabel(groupBox_6);
        labelY1->setObjectName(QString::fromUtf8("labelY1"));

        gridLayout->addWidget(labelY1, 0, 1, 1, 1);

        labelY2 = new QLabel(groupBox_6);
        labelY2->setObjectName(QString::fromUtf8("labelY2"));

        gridLayout->addWidget(labelY2, 1, 0, 1, 1);

        labelX2 = new QLabel(groupBox_6);
        labelX2->setObjectName(QString::fromUtf8("labelX2"));

        gridLayout->addWidget(labelX2, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_6, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(SettingCaptureFrame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        defDistInPixels = new QPushButton(groupBox_2);
        defDistInPixels->setObjectName(QString::fromUtf8("defDistInPixels"));

        gridLayout_2->addWidget(defDistInPixels, 0, 0, 1, 2);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        pixels = new QLabel(groupBox_2);
        pixels->setObjectName(QString::fromUtf8("pixels"));

        gridLayout_2->addWidget(pixels, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 3, 0, 1, 1);

        groupBox_3 = new QGroupBox(SettingCaptureFrame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        widthCaptureWindow = new QSpinBox(groupBox_3);
        widthCaptureWindow->setObjectName(QString::fromUtf8("widthCaptureWindow"));

        horizontalLayout_3->addWidget(widthCaptureWindow);

        pushButtonOk = new QPushButton(groupBox_3);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));

        horizontalLayout_3->addWidget(pushButtonOk);


        gridLayout_4->addWidget(groupBox_3, 4, 0, 1, 1);

        pushButtonStart = new QPushButton(SettingCaptureFrame);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));

        gridLayout_4->addWidget(pushButtonStart, 6, 0, 1, 1);

        groupBox_4 = new QGroupBox(SettingCaptureFrame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        SettingApply = new QPushButton(groupBox_4);
        SettingApply->setObjectName(QString::fromUtf8("SettingApply"));

        verticalLayout_2->addWidget(SettingApply);

        SettingCansel = new QPushButton(groupBox_4);
        SettingCansel->setObjectName(QString::fromUtf8("SettingCansel"));

        verticalLayout_2->addWidget(SettingCansel);

        SettingStandart = new QPushButton(groupBox_4);
        SettingStandart->setObjectName(QString::fromUtf8("SettingStandart"));

        verticalLayout_2->addWidget(SettingStandart);


        gridLayout_4->addWidget(groupBox_4, 7, 0, 1, 1);

        frame = new QFrame(SettingCaptureFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 3);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_5->addWidget(checkBox, 0, 3, 1, 2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 1, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_5->addWidget(doubleSpinBox, 1, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(frame);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout_5->addWidget(doubleSpinBox_2, 1, 4, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 1, 3, 1, 1);


        gridLayout_4->addWidget(frame, 5, 0, 1, 1);


        retranslateUi(SettingCaptureFrame);

        QMetaObject::connectSlotsByName(SettingCaptureFrame);
    } // setupUi

    void retranslateUi(QWidget *SettingCaptureFrame)
    {
        SettingCaptureFrame->setWindowTitle(QApplication::translate("SettingCaptureFrame", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QString());
        label_2->setText(QApplication::translate("SettingCaptureFrame", "\320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\274\321\226\320\273\321\226\320\274\320\265\321\202\321\200\321\226\320\262", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingCaptureFrame", "\320\277\320\265\321\200\321\226\320\276\320\264 \320\262\320\267\321\217\321\202\321\202\321\217 \320\272\320\260\320\264\321\200\321\203", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        defRect->setText(QApplication::translate("SettingCaptureFrame", "\320\262\320\270\320\267\320\275\320\260\321\207\320\270\321\202\320\270 \320\275\320\265\320\276\320\261\321\205\321\226\320\264\320\275\321\203 \320\276\320\261\320\273\320\260\321\201\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\320\270", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("SettingCaptureFrame", "\320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        labelX1->setText(QApplication::translate("SettingCaptureFrame", "x1=", 0, QApplication::UnicodeUTF8));
        labelY1->setText(QApplication::translate("SettingCaptureFrame", "y1=", 0, QApplication::UnicodeUTF8));
        labelY2->setText(QApplication::translate("SettingCaptureFrame", "y2=", 0, QApplication::UnicodeUTF8));
        labelX2->setText(QApplication::translate("SettingCaptureFrame", "x2=", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        defDistInPixels->setText(QApplication::translate("SettingCaptureFrame", "\320\262\320\270\320\267\320\275\320\260\321\207\320\270\321\202\320\270 \320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\277\321\226\320\272\321\201\320\265\320\273\321\226\320\262", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SettingCaptureFrame", "\320\272\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\277\321\226\320\272\321\201\320\265\320\273\321\226\320\262 ", 0, QApplication::UnicodeUTF8));
        pixels->setText(QApplication::translate("SettingCaptureFrame", "53748757", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("SettingCaptureFrame", "\320\261\320\260\320\266\320\260\320\275\320\270\320\271 \321\200\320\276\320\267\320\274\321\226\321\200 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SettingCaptureFrame", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", 0, QApplication::UnicodeUTF8));
        pushButtonOk->setText(QApplication::translate("SettingCaptureFrame", "\320\267\320\260\321\201\321\202\320\276\321\201\321\203\320\262\320\260\321\202\320\270", 0, QApplication::UnicodeUTF8));
        pushButtonStart->setText(QApplication::translate("SettingCaptureFrame", "\321\201\320\277\320\276\321\207\320\260\321\202\320\272\321\203", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        SettingApply->setText(QApplication::translate("SettingCaptureFrame", "\320\267\320\260\321\201\321\202\320\276\321\201\321\203\320\262\320\260\321\202\320\270 \320\275\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        SettingCansel->setText(QApplication::translate("SettingCaptureFrame", "\320\262\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270 \320\275\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", 0, QApplication::UnicodeUTF8));
        SettingStandart->setText(QApplication::translate("SettingCaptureFrame", "\320\277\320\276 \320\267\320\260\320\274\320\276\320\262\321\207\321\203\320\262\320\260\320\275\320\275\321\216", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SettingCaptureFrame", "\320\267\320\274\321\226\320\275\320\270\321\202\320\270 \320\272\320\276\320\265\321\204\321\226\321\206\321\226\321\224\320\275\321\202\320\270", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("SettingCaptureFrame", "\320\262\321\226\320\264\320\276\320\261\321\200\320\260\320\267\320\270\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingCaptureFrame", "k1=", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SettingCaptureFrame", "k2=", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingCaptureFrame: public Ui_SettingCaptureFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGCAPTUREFRAME_H
