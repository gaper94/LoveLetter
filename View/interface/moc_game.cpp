/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[10];
    char stringdata[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Game_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 21),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 23),
QT_MOC_LITERAL(4, 52, 24),
QT_MOC_LITERAL(5, 77, 15),
QT_MOC_LITERAL(6, 93, 15),
QT_MOC_LITERAL(7, 109, 19),
QT_MOC_LITERAL(8, 129, 18),
QT_MOC_LITERAL(9, 148, 23)
    },
    "Game\0on_pushButton_clicked\0\0"
    "on_pushButton_9_clicked\0"
    "on_pushButton_10_clicked\0affiche_combo_J\0"
    "affiche_combo_C\0afficheCardsDiscard\0"
    "cacheCardsDiscards\0on_pushButton_8_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    0,   57,    2, 0x08,
       6,    0,   58,    2, 0x08,
       7,    0,   59,    2, 0x08,
       8,    0,   60,    2, 0x08,
       9,    0,   61,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game *_t = static_cast<Game *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_9_clicked(); break;
        case 2: _t->on_pushButton_10_clicked(); break;
        case 3: _t->affiche_combo_J(); break;
        case 4: _t->affiche_combo_C(); break;
        case 5: _t->afficheCardsDiscard(); break;
        case 6: _t->cacheCardsDiscards(); break;
        case 7: _t->on_pushButton_8_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Game::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Game.data,
      qt_meta_data_Game,  qt_static_metacall, 0, 0}
};


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata))
        return static_cast<void*>(const_cast< Game*>(this));
    return QDialog::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
