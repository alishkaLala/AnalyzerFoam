/********************************************************************************
** Form generated from reading UI file 'infoframe.ui'
**
** Created: Tue 5. Mar 01:38:40 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOFRAME_H
#define UI_INFOFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoFrame
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *InfoFrame)
    {
        if (InfoFrame->objectName().isEmpty())
            InfoFrame->setObjectName(QString::fromUtf8("InfoFrame"));
        InfoFrame->resize(400, 300);
        gridLayout = new QGridLayout(InfoFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(InfoFrame);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        pushButton = new QPushButton(InfoFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(InfoFrame);

        QMetaObject::connectSlotsByName(InfoFrame);
    } // setupUi

    void retranslateUi(QWidget *InfoFrame)
    {
        InfoFrame->setWindowTitle(QApplication::translate("InfoFrame", "Form", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("InfoFrame", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Bla BLA </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("InfoFrame", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InfoFrame: public Ui_InfoFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOFRAME_H
