/****************************************************************************
** Meta object code from reading C++ file 'computer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "computer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'computer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Computer_t {
    QByteArrayData data[9];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Computer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Computer_t qt_meta_stringdata_Computer = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 22),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 11),
QT_MOC_LITERAL(4, 45, 3),
QT_MOC_LITERAL(5, 49, 21),
QT_MOC_LITERAL(6, 71, 7),
QT_MOC_LITERAL(7, 79, 23),
QT_MOC_LITERAL(8, 103, 21)
    },
    "Computer\0on_startButton_clicked\0\0"
    "TextChanged\0str\0on_easyButton_toggled\0"
    "checked\0on_mediumButton_toggled\0"
    "on_hardButton_toggled\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Computer[] = {

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
       1,    0,   39,    2, 0x08,
       3,    1,   40,    2, 0x08,
       5,    1,   43,    2, 0x08,
       7,    1,   46,    2, 0x08,
       8,    1,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void Computer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Computer *_t = static_cast<Computer *>(_o);
        switch (_id) {
        case 0: _t->on_startButton_clicked(); break;
        case 1: _t->TextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_easyButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_mediumButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_hardButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Computer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Computer.data,
      qt_meta_data_Computer,  qt_static_metacall, 0, 0}
};


const QMetaObject *Computer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Computer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Computer.stringdata))
        return static_cast<void*>(const_cast< Computer*>(this));
    return QDialog::qt_metacast(_clname);
}

int Computer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
