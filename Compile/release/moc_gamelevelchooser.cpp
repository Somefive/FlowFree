/****************************************************************************
** Meta object code from reading C++ file 'gamelevelchooser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FlowGame/ViewComponent/gamelevelchooser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamelevelchooser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameLevelChooser_t {
    QByteArrayData data[6];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameLevelChooser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameLevelChooser_t qt_meta_stringdata_GameLevelChooser = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GameLevelChooser"
QT_MOC_LITERAL(1, 17, 9), // "StartGame"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "BackToMenu"
QT_MOC_LITERAL(4, 39, 20), // "ConfirmButtonPressed"
QT_MOC_LITERAL(5, 60, 17) // "MenuButtonPressed"

    },
    "GameLevelChooser\0StartGame\0\0BackToMenu\0"
    "ConfirmButtonPressed\0MenuButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameLevelChooser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       3,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   40,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameLevelChooser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameLevelChooser *_t = static_cast<GameLevelChooser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->StartGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->BackToMenu(); break;
        case 2: _t->ConfirmButtonPressed(); break;
        case 3: _t->MenuButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameLevelChooser::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameLevelChooser::StartGame)) {
                *result = 0;
            }
        }
        {
            typedef void (GameLevelChooser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameLevelChooser::BackToMenu)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GameLevelChooser::staticMetaObject = {
    { &GameViewPanel::staticMetaObject, qt_meta_stringdata_GameLevelChooser.data,
      qt_meta_data_GameLevelChooser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameLevelChooser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameLevelChooser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameLevelChooser.stringdata0))
        return static_cast<void*>(const_cast< GameLevelChooser*>(this));
    return GameViewPanel::qt_metacast(_clname);
}

int GameLevelChooser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameViewPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GameLevelChooser::StartGame(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameLevelChooser::BackToMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
