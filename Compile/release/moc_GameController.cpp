/****************************************************************************
** Meta object code from reading C++ file 'GameController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FlowGame/GameController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameController_t {
    QByteArrayData data[15];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameController_t qt_meta_stringdata_GameController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GameController"
QT_MOC_LITERAL(1, 15, 12), // "CompletePipe"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "Pipe*"
QT_MOC_LITERAL(4, 35, 9), // "BreakPipe"
QT_MOC_LITERAL(5, 45, 11), // "ForwardPipe"
QT_MOC_LITERAL(6, 57, 12), // "BackwardPipe"
QT_MOC_LITERAL(7, 70, 17), // "UpdatePipeDisplay"
QT_MOC_LITERAL(8, 88, 18), // "UpdateBlockDisplay"
QT_MOC_LITERAL(9, 107, 12), // "CompleteGame"
QT_MOC_LITERAL(10, 120, 18), // "CoordinateSelected"
QT_MOC_LITERAL(11, 139, 17), // "CoordinateChanged"
QT_MOC_LITERAL(12, 157, 18), // "CoordinateReleased"
QT_MOC_LITERAL(13, 176, 20), // "GameStateRecalculate"
QT_MOC_LITERAL(14, 197, 10) // "AnswerGame"

    },
    "GameController\0CompletePipe\0\0Pipe*\0"
    "BreakPipe\0ForwardPipe\0BackwardPipe\0"
    "UpdatePipeDisplay\0UpdateBlockDisplay\0"
    "CompleteGame\0CoordinateSelected\0"
    "CoordinateChanged\0CoordinateReleased\0"
    "GameStateRecalculate\0AnswerGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    0,   80,    2, 0x06 /* Public */,
       6,    0,   81,    2, 0x06 /* Public */,
       7,    0,   82,    2, 0x06 /* Public */,
       8,    0,   83,    2, 0x06 /* Public */,
       9,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   85,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameController *_t = static_cast<GameController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CompletePipe((*reinterpret_cast< Pipe*(*)>(_a[1]))); break;
        case 1: _t->BreakPipe((*reinterpret_cast< Pipe*(*)>(_a[1]))); break;
        case 2: _t->ForwardPipe(); break;
        case 3: _t->BackwardPipe(); break;
        case 4: _t->UpdatePipeDisplay(); break;
        case 5: _t->UpdateBlockDisplay(); break;
        case 6: _t->CompleteGame(); break;
        case 7: _t->CoordinateSelected((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->CoordinateChanged((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->CoordinateReleased(); break;
        case 10: _t->GameStateRecalculate(); break;
        case 11: _t->AnswerGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameController::*_t)(Pipe * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::CompletePipe)) {
                *result = 0;
            }
        }
        {
            typedef void (GameController::*_t)(Pipe * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::BreakPipe)) {
                *result = 1;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::ForwardPipe)) {
                *result = 2;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::BackwardPipe)) {
                *result = 3;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::UpdatePipeDisplay)) {
                *result = 4;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::UpdateBlockDisplay)) {
                *result = 5;
            }
        }
        {
            typedef void (GameController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameController::CompleteGame)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject GameController::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameController.data,
      qt_meta_data_GameController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameController.stringdata0))
        return static_cast<void*>(const_cast< GameController*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void GameController::CompletePipe(Pipe * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameController::BreakPipe(Pipe * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameController::ForwardPipe()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void GameController::BackwardPipe()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void GameController::UpdatePipeDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void GameController::UpdateBlockDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void GameController::CompleteGame()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
