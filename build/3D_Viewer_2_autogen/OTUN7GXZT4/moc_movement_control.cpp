/****************************************************************************
** Meta object code from reading C++ file 'movement_control.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/view/movement_control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'movement_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__MovementControl_t {
    const uint offsetsAndSize[16];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__MovementControl_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__MovementControl_t qt_meta_stringdata_s21__MovementControl = {
    {
QT_MOC_LITERAL(0, 20), // "s21::MovementControl"
QT_MOC_LITERAL(21, 19), // "MoveOnXAxisPositive"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 19), // "MoveOnXAxisNegative"
QT_MOC_LITERAL(62, 19), // "MoveOnYAxisPositive"
QT_MOC_LITERAL(82, 19), // "MoveOnYAxisNegative"
QT_MOC_LITERAL(102, 19), // "MoveOnZAxisPositive"
QT_MOC_LITERAL(122, 19) // "MoveOnZAxisNegative"

    },
    "s21::MovementControl\0MoveOnXAxisPositive\0"
    "\0MoveOnXAxisNegative\0MoveOnYAxisPositive\0"
    "MoveOnYAxisNegative\0MoveOnZAxisPositive\0"
    "MoveOnZAxisNegative"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__MovementControl[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void s21::MovementControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MovementControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MoveOnXAxisPositive(); break;
        case 1: _t->MoveOnXAxisNegative(); break;
        case 2: _t->MoveOnYAxisPositive(); break;
        case 3: _t->MoveOnYAxisNegative(); break;
        case 4: _t->MoveOnZAxisPositive(); break;
        case 5: _t->MoveOnZAxisNegative(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject s21::MovementControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_s21__MovementControl.offsetsAndSize,
    qt_meta_data_s21__MovementControl,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__MovementControl_t
, QtPrivate::TypeAndForceComplete<MovementControl, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21::MovementControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::MovementControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__MovementControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int s21::MovementControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
