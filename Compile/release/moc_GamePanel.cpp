/****************************************************************************
** Meta object code from reading C++ file 'GamePanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FlowGame/GamePanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GamePanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GamePanel_t {
    QByteArrayData data[19];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GamePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GamePanel_t qt_meta_stringdata_GamePanel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GamePanel"
QT_MOC_LITERAL(1, 10, 18), // "CoordinateSelected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "_coordinate"
QT_MOC_LITERAL(4, 42, 17), // "CoordinateChanged"
QT_MOC_LITERAL(5, 60, 18), // "CoordinateReleased"
QT_MOC_LITERAL(6, 79, 5), // "Retry"
QT_MOC_LITERAL(7, 85, 10), // "BackToMenu"
QT_MOC_LITERAL(8, 96, 8), // "NextGame"
QT_MOC_LITERAL(9, 105, 12), // "PreviousGame"
QT_MOC_LITERAL(10, 118, 10), // "AnswerGame"
QT_MOC_LITERAL(11, 129, 17), // "UpdatePipeDisplay"
QT_MOC_LITERAL(12, 147, 18), // "UpdateBlockDisplay"
QT_MOC_LITERAL(13, 166, 14), // "RetryActivated"
QT_MOC_LITERAL(14, 181, 13), // "MenuActivated"
QT_MOC_LITERAL(15, 195, 17), // "NextGameActivated"
QT_MOC_LITERAL(16, 213, 21), // "PreviousGameActivated"
QT_MOC_LITERAL(17, 235, 19), // "AnswerGameActivated"
QT_MOC_LITERAL(18, 255, 12) // "CompleteGame"

    },
    "GamePanel\0CoordinateSelected\0\0_coordinate\0"
    "CoordinateChanged\0CoordinateReleased\0"
    "Retry\0BackToMenu\0NextGame\0PreviousGame\0"
    "AnswerGame\0UpdatePipeDisplay\0"
    "UpdateBlockDisplay\0RetryActivated\0"
    "MenuActivated\0NextGameActivated\0"
    "PreviousGameActivated\0AnswerGameActivated\0"
    "CompleteGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamePanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    0,  100,    2, 0x06 /* Public */,
       6,    0,  101,    2, 0x06 /* Public */,
       7,    0,  102,    2, 0x06 /* Public */,
       8,    0,  103,    2, 0x06 /* Public */,
       9,    0,  104,    2, 0x06 /* Public */,
      10,    0,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  106,    2, 0x0a /* Public */,
      12,    0,  107,    2, 0x0a /* Public */,
      13,    0,  108,    2, 0x0a /* Public */,
      14,    0,  109,    2, 0x0a /* Public */,
      15,    0,  110,    2, 0x0a /* Public */,
      16,    0,  111,    2, 0x0a /* Public */,
      17,    0,  112,    2, 0x0a /* Public */,
      18,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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

void GamePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GamePanel *_t = static_cast<GamePanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CoordinateSelected((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->CoordinateChanged((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->CoordinateReleased(); break;
        case 3: _t->Retry(); break;
        case 4: _t->BackToMenu(); break;
        case 5: _t->NextGame(); break;
        case 6: _t->PreviousGame(); break;
        case 7: _t->AnswerGame(); break;
        case 8: _t->UpdatePipeDisplay(); break;
        case 9: _t->UpdateBlockDisplay(); break;
        case 10: _t->RetryActivated(); break;
        case 11: _t->MenuActivated(); break;
        case 12: _t->NextGameActivated(); break;
        case 13: _t->PreviousGameActivated(); break;
        case 14: _t->AnswerGameActivated(); break;
        case 15: _t->CompleteGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GamePanel::*_t)(const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::CoordinateSelected)) {
                *result = 0;
            }
        }
        {
            typedef void (GamePanel::*_t)(const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::CoordinateChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (GamePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::CoordinateReleased)) {
                *result = 2;
            }
        }
        {
            typedef void (GamePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::Retry)) {
                *result = 3;
            }
        }
        {
            typedef void (GamePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::BackToMenu)) {
                *result = 4;
            }
        }
        {
            typedef void (GamePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::NextGame)) {
                *result = 5;
            }
        }
        {
            typedef void (GamePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::PreviousGame)) {
                *result = 6;
            }
        }
        {
            typedef void (GamePanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GamePanel::AnswerGame)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject GamePanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GamePanel.data,
      qt_meta_data_GamePanel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GamePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GamePanel.stringdata0))
        return static_cast<void*>(const_cast< GamePanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int GamePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void GamePanel::CoordinateSelected(const QPoint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GamePanel::CoordinateChanged(const QPoint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GamePanel::CoordinateReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void GamePanel::Retry()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void GamePanel::BackToMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void GamePanel::NextGame()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void GamePanel::PreviousGame()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void GamePanel::AnswerGame()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
