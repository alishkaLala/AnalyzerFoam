/****************************************************************************
** Meta object code from reading C++ file 'settingmainframes.h'
**
** Created: Tue 5. Mar 01:39:06 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnalyzerFoam/settingmainframes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingmainframes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingMainFrames[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      45,   18,   18,   18, 0x08,
      71,   18,   18,   18, 0x08,
      97,   18,   18,   18, 0x08,
     123,   18,   18,   18, 0x08,
     149,   18,   18,   18, 0x08,
     175,   18,   18,   18, 0x08,
     201,   18,   18,   18, 0x08,
     228,   18,   18,   18, 0x08,
     255,   18,   18,   18, 0x08,
     280,   18,   18,   18, 0x08,
     307,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SettingMainFrames[] = {
    "SettingMainFrames\0\0on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_SaveSetting_clicked()\0"
    "on_CanselSetting_clicked()\0"
    "on_Standart_clicked()\0"
};

const QMetaObject SettingMainFrames::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SettingMainFrames,
      qt_meta_data_SettingMainFrames, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingMainFrames::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingMainFrames::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingMainFrames::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingMainFrames))
        return static_cast<void*>(const_cast< SettingMainFrames*>(this));
    return QWidget::qt_metacast(_clname);
}

int SettingMainFrames::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_4_clicked(); break;
        case 1: on_pushButton_5_clicked(); break;
        case 2: on_pushButton_6_clicked(); break;
        case 3: on_pushButton_7_clicked(); break;
        case 4: on_pushButton_8_clicked(); break;
        case 5: on_pushButton_9_clicked(); break;
        case 6: on_pushButton_3_clicked(); break;
        case 7: on_pushButton_10_clicked(); break;
        case 8: on_pushButton_11_clicked(); break;
        case 9: on_SaveSetting_clicked(); break;
        case 10: on_CanselSetting_clicked(); break;
        case 11: on_Standart_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
