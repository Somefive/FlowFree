/****************************************************************************
** Meta object code from reading C++ file 'GameAudioPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FlowGame/GameAudioPlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameAudioPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameAudioPlayer_t {
    QByteArrayData data[8];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameAudioPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameAudioPlayer_t qt_meta_stringdata_GameAudioPlayer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GameAudioPlayer"
QT_MOC_LITERAL(1, 16, 12), // "CompletePipe"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "Pipe*"
QT_MOC_LITERAL(4, 36, 9), // "BreakPipe"
QT_MOC_LITERAL(5, 46, 12), // "CompleteGame"
QT_MOC_LITERAL(6, 59, 11), // "ForwardPipe"
QT_MOC_LITERAL(7, 71, 12) // "BackwardPipe"

    },
    "GameAudioPlayer\0CompletePipe\0\0Pipe*\0"
    "BreakPipe\0CompleteGame\0ForwardPipe\0"
    "BackwardPipe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameAudioPlayer[] = {

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
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    0,   45,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x0a /* Public */,
       7,    0,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameAudioPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameAudioPlayer *_t = static_cast<GameAudioPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CompletePipe((*reinterpret_cast< Pipe*(*)>(_a[1]))); break;
        case 1: _t->BreakPipe((*reinterpret_cast< Pipe*(*)>(_a[1]))); break;
        case 2: _t->CompleteGame(); break;
        case 3: _t->ForwardPipe(); break;
        case 4: _t->BackwardPipe(); break;
        default: ;
        }
    }
}

const QMetaObject GameAudioPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameAudioPlayer.data,
      qt_meta_data_GameAudioPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameAudioPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameAudioPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameAudioPlayer.stringdata0))
        return static_cast<void*>(const_cast< GameAudioPlayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameAudioPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
