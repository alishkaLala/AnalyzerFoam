/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 5. Mar 01:39:01 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      81,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     118,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     221,   11,   11,   11, 0x08,
     243,  239,   11,   11, 0x08,
     275,  267,   11,   11, 0x08,
     319,  305,   11,   11, 0x08,
     346,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0captureChoised(int)\0"
    "on_pushButton_clicked()\0"
    "on_buttonStart_clicked()\0"
    "on_buttonStop_clicked()\0captureOff()\0"
    "hideCapture()\0showCapture()\0"
    "showAboutProgram()\0showInfoFrame()\0"
    "showSettingFrame()\0showSettingCapture()\0"
    "showOpenGLGraph()\0img\0imageGetting(IplImage*)\0"
    "enabled\0setSartStopImegeGetting(bool)\0"
    "count,diametr\0infoGetting(double,double)\0"
    "on_pushButton_2_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: captureChoised((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_pushButton_clicked(); break;
        case 2: on_buttonStart_clicked(); break;
        case 3: on_buttonStop_clicked(); break;
        case 4: captureOff(); break;
        case 5: hideCapture(); break;
        case 6: showCapture(); break;
        case 7: showAboutProgram(); break;
        case 8: showInfoFrame(); break;
        case 9: showSettingFrame(); break;
        case 10: showSettingCapture(); break;
        case 11: showOpenGLGraph(); break;
        case 12: imageGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 13: setSartStopImegeGetting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: infoGetting((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 15: on_pushButton_2_clicked(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
