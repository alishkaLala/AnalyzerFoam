/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 5. Mar 01:38:40 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelper;
    QAction *actionDisable_capture;
    QAction *actionConfiguration_of_program;
    QAction *actionConfiguration_of_capture;
    QAction *actionOf_export;
    QAction *actionStart_testing;
    QAction *actionTo_fail;
    QAction *actionTo_graphik;
    QAction *actionPrint;
    QAction *actionInformation;
    QAction *action1;
    QAction *actionHide_capture;
    QAction *actionShow_capture;
    QAction *actionShowFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QPushButton *buttonStart;
    QPushButton *buttonStop;
    QSpinBox *spinBox;
    QCheckBox *processingImageShow;
    QCheckBox *checkBox;
    QLabel *capturePicture;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menuExport;
    QMenu *menuCapture;
    QMenu *menuChoise_capture;
    QMenu *menuSetting;
    QMenu *menuInformation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(596, 377);
        actionHelper = new QAction(MainWindow);
        actionHelper->setObjectName(QString::fromUtf8("actionHelper"));
        actionDisable_capture = new QAction(MainWindow);
        actionDisable_capture->setObjectName(QString::fromUtf8("actionDisable_capture"));
        actionConfiguration_of_program = new QAction(MainWindow);
        actionConfiguration_of_program->setObjectName(QString::fromUtf8("actionConfiguration_of_program"));
        actionConfiguration_of_capture = new QAction(MainWindow);
        actionConfiguration_of_capture->setObjectName(QString::fromUtf8("actionConfiguration_of_capture"));
        actionOf_export = new QAction(MainWindow);
        actionOf_export->setObjectName(QString::fromUtf8("actionOf_export"));
        actionStart_testing = new QAction(MainWindow);
        actionStart_testing->setObjectName(QString::fromUtf8("actionStart_testing"));
        actionTo_fail = new QAction(MainWindow);
        actionTo_fail->setObjectName(QString::fromUtf8("actionTo_fail"));
        actionTo_graphik = new QAction(MainWindow);
        actionTo_graphik->setObjectName(QString::fromUtf8("actionTo_graphik"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName(QString::fromUtf8("actionInformation"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QString::fromUtf8("action1"));
        actionHide_capture = new QAction(MainWindow);
        actionHide_capture->setObjectName(QString::fromUtf8("actionHide_capture"));
        actionShow_capture = new QAction(MainWindow);
        actionShow_capture->setObjectName(QString::fromUtf8("actionShow_capture"));
        actionShowFile = new QAction(MainWindow);
        actionShowFile->setObjectName(QString::fromUtf8("actionShowFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 3);

        horizontalSlider = new QSlider(groupBox_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 1, 0, 1, 3);

        buttonStart = new QPushButton(groupBox_2);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        gridLayout_2->addWidget(buttonStart, 2, 0, 1, 1);

        buttonStop = new QPushButton(groupBox_2);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));

        gridLayout_2->addWidget(buttonStop, 2, 1, 1, 1);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout_2->addWidget(spinBox, 2, 2, 1, 1);

        processingImageShow = new QCheckBox(groupBox_2);
        processingImageShow->setObjectName(QString::fromUtf8("processingImageShow"));

        gridLayout_2->addWidget(processingImageShow, 4, 0, 1, 3);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 3, 0, 1, 3);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        capturePicture = new QLabel(centralWidget);
        capturePicture->setObjectName(QString::fromUtf8("capturePicture"));
        capturePicture->setMinimumSize(QSize(250, 250));
        capturePicture->setMaximumSize(QSize(16777215, 16777215));
        capturePicture->setScaledContents(true);

        gridLayout_3->addWidget(capturePicture, 0, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 596, 21));
        menuExport = new QMenu(menuBar);
        menuExport->setObjectName(QString::fromUtf8("menuExport"));
        menuCapture = new QMenu(menuBar);
        menuCapture->setObjectName(QString::fromUtf8("menuCapture"));
        menuChoise_capture = new QMenu(menuCapture);
        menuChoise_capture->setObjectName(QString::fromUtf8("menuChoise_capture"));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuInformation = new QMenu(menuBar);
        menuInformation->setObjectName(QString::fromUtf8("menuInformation"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCapture->menuAction());
        menuBar->addAction(menuExport->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuInformation->menuAction());
        menuExport->addAction(actionTo_fail);
        menuExport->addAction(actionTo_graphik);
        menuExport->addSeparator();
        menuExport->addAction(actionPrint);
        menuExport->addAction(actionShowFile);
        menuCapture->addAction(menuChoise_capture->menuAction());
        menuCapture->addSeparator();
        menuCapture->addAction(actionDisable_capture);
        menuCapture->addSeparator();
        menuCapture->addAction(actionHide_capture);
        menuCapture->addAction(actionShow_capture);
        menuChoise_capture->addAction(action1);
        menuSetting->addAction(actionConfiguration_of_program);
        menuSetting->addAction(actionConfiguration_of_capture);
        menuSetting->addAction(actionOf_export);
        menuSetting->addSeparator();
        menuSetting->addAction(actionStart_testing);
        menuInformation->addAction(actionHelper);
        menuInformation->addAction(actionInformation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionHelper->setText(QApplication::translate("MainWindow", "Helper", 0, QApplication::UnicodeUTF8));
        actionDisable_capture->setText(QApplication::translate("MainWindow", "Disable capture ", 0, QApplication::UnicodeUTF8));
        actionConfiguration_of_program->setText(QApplication::translate("MainWindow", "of program...", 0, QApplication::UnicodeUTF8));
        actionConfiguration_of_capture->setText(QApplication::translate("MainWindow", "of capture... ", 0, QApplication::UnicodeUTF8));
        actionOf_export->setText(QApplication::translate("MainWindow", "of export", 0, QApplication::UnicodeUTF8));
        actionStart_testing->setText(QApplication::translate("MainWindow", "start testing..", 0, QApplication::UnicodeUTF8));
        actionTo_fail->setText(QApplication::translate("MainWindow", "to fail", 0, QApplication::UnicodeUTF8));
        actionTo_graphik->setText(QApplication::translate("MainWindow", "to graphik", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "print ", 0, QApplication::UnicodeUTF8));
        actionInformation->setText(QApplication::translate("MainWindow", "information", 0, QApplication::UnicodeUTF8));
        action1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        actionHide_capture->setText(QApplication::translate("MainWindow", "Hide capture", 0, QApplication::UnicodeUTF8));
        actionShow_capture->setText(QApplication::translate("MainWindow", "Show capture", 0, QApplication::UnicodeUTF8));
        actionShowFile->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\320\270 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Information", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonStart->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        buttonStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        processingImageShow->setText(QApplication::translate("MainWindow", "\320\262\320\270\320\262\320\276\320\264\320\270  \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217, \321\211\320\276 \320\276\320\261\321\200\320\276\320\261\320\273\321\217\321\224\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "\320\276\320\264\321\200\320\260\320\267\321\203 \321\200\320\276\320\267\320\277\320\276\321\207\320\260\321\202\320\270 \321\215\320\272\321\201\320\277\320\276\321\200\321\202 \321\203 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        capturePicture->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
        menuCapture->setTitle(QApplication::translate("MainWindow", "Capture", 0, QApplication::UnicodeUTF8));
        menuChoise_capture->setTitle(QApplication::translate("MainWindow", "Choise  capture", 0, QApplication::UnicodeUTF8));
        menuSetting->setTitle(QApplication::translate("MainWindow", "Setting", 0, QApplication::UnicodeUTF8));
        menuInformation->setTitle(QApplication::translate("MainWindow", "information", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
