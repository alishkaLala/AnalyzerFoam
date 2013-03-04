/****************************************************************************
** Meta object code from reading C++ file 'settingcaptureframe.h'
**
** Created: Tue 5. Mar 01:39:08 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/settingcaptureframe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingcaptureframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingCaptureFrame[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      32,   20,   20,   20, 0x08,
      44,   20,   20,   20, 0x08,
      60,   20,   20,   20, 0x08,
      85,   20,   20,   20, 0x08,
     108,  106,   20,   20, 0x08,
     139,   20,   20,   20, 0x08,
     168,   20,   20,   20, 0x08,
     194,   20,   20,   20, 0x08,
     220,   20,   20,   20, 0x08,
     246,   20,   20,   20, 0x08,
     272,   20,   20,   20, 0x08,
     298,   20,   20,   20, 0x08,
     324,   20,   20,   20, 0x08,
     351,   20,   20,   20, 0x08,
     380,   20,   20,   20, 0x08,
     406,   20,   20,   20, 0x08,
     435,   20,   20,   20, 0x08,
     461,  457,   20,   20, 0x08,
     496,  457,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SettingCaptureFrame[] = {
    "SettingCaptureFrame\0\0stopWork()\0"
    "toolTipMm()\0validMmAndSet()\0"
    "timerEvent_showCapture()\0on_defRect_clicked()\0"
    "w\0calculateCaptureSizeFrame(int)\0"
    "on_defDistInPixels_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButtonNo_clicked()\0"
    "on_pushButtonOk_clicked()\0"
    "on_SettingCansel_clicked()\0"
    "on_SettingStandart_clicked()\0"
    "on_SettingApply_clicked()\0"
    "on_pushButtonStart_clicked()\0"
    "setValueShowing(bool)\0img\0"
    "imageCalculatingGetting(IplImage*)\0"
    "imageGetting(IplImage*)\0"
};

const QMetaObject SettingCaptureFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SettingCaptureFrame,
      qt_meta_data_SettingCaptureFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingCaptureFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingCaptureFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingCaptureFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingCaptureFrame))
        return static_cast<void*>(const_cast< SettingCaptureFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int SettingCaptureFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stopWork(); break;
        case 1: toolTipMm(); break;
        case 2: validMmAndSet(); break;
        case 3: timerEvent_showCapture(); break;
        case 4: on_defRect_clicked(); break;
        case 5: calculateCaptureSizeFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_defDistInPixels_clicked(); break;
        case 7: on_pushButton_3_clicked(); break;
        case 8: on_pushButton_7_clicked(); break;
        case 9: on_pushButton_8_clicked(); break;
        case 10: on_pushButton_9_clicked(); break;
        case 11: on_pushButtonNo_clicked(); break;
        case 12: on_pushButtonOk_clicked(); break;
        case 13: on_SettingCansel_clicked(); break;
        case 14: on_SettingStandart_clicked(); break;
        case 15: on_SettingApply_clicked(); break;
        case 16: on_pushButtonStart_clicked(); break;
        case 17: setValueShowing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: imageCalculatingGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        case 19: imageGetting((*reinterpret_cast< IplImage*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
