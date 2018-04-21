/****************************************************************************
** Meta object code from reading C++ file 'playernumber.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "playernumber.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playernumber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PlayerNumber_t {
    QByteArrayData data[8];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PlayerNumber_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PlayerNumber_t qt_meta_stringdata_PlayerNumber = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 27),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 7),
QT_MOC_LITERAL(4, 50, 29),
QT_MOC_LITERAL(5, 80, 28),
QT_MOC_LITERAL(6, 109, 25),
QT_MOC_LITERAL(7, 135, 23)
    },
    "PlayerNumber\0on_twoPlayersButton_toggled\0"
    "\0checked\0on_threePlayersButton_toggled\0"
    "on_fourPlayersButton_toggled\0"
    "on_computerButton_clicked\0"
    "on_onlineButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerNumber[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       4,    1,   42,    2, 0x08,
       5,    1,   45,    2, 0x08,
       6,    0,   48,    2, 0x08,
       7,    0,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayerNumber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerNumber *_t = static_cast<PlayerNumber *>(_o);
        switch (_id) {
        case 0: _t->on_twoPlayersButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_threePlayersButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_fourPlayersButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_computerButton_clicked(); break;
        case 4: _t->on_onlineButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PlayerNumber::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PlayerNumber.data,
      qt_meta_data_PlayerNumber,  qt_static_metacall, 0, 0}
};


const QMetaObject *PlayerNumber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerNumber::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerNumber.stringdata))
        return static_cast<void*>(const_cast< PlayerNumber*>(this));
    return QDialog::qt_metacast(_clname);
}

int PlayerNumber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
