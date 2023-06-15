/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__Controller_t {
    const uint offsetsAndSize[24];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_s21__Controller_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_s21__Controller_t qt_meta_stringdata_s21__Controller = {
    {
QT_MOC_LITERAL(0, 15), // "s21::Controller"
QT_MOC_LITERAL(16, 17), // "RotateAroundXAxis"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 5), // "angle"
QT_MOC_LITERAL(41, 17), // "RotateAroundYAxis"
QT_MOC_LITERAL(59, 17), // "RotateAroundZAxis"
QT_MOC_LITERAL(77, 12), // "ShiftOnXAxis"
QT_MOC_LITERAL(90, 6), // "length"
QT_MOC_LITERAL(97, 12), // "ShiftOnYAxis"
QT_MOC_LITERAL(110, 12), // "ShiftOnZAxis"
QT_MOC_LITERAL(123, 7), // "Scaling"
QT_MOC_LITERAL(131, 5) // "scale"

    },
    "s21::Controller\0RotateAroundXAxis\0\0"
    "angle\0RotateAroundYAxis\0RotateAroundZAxis\0"
    "ShiftOnXAxis\0length\0ShiftOnYAxis\0"
    "ShiftOnZAxis\0Scaling\0scale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__Controller[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x0a,    1 /* Public */,
       4,    1,   59,    2, 0x0a,    3 /* Public */,
       5,    1,   62,    2, 0x0a,    5 /* Public */,
       6,    1,   65,    2, 0x0a,    7 /* Public */,
       8,    1,   68,    2, 0x0a,    9 /* Public */,
       9,    1,   71,    2, 0x0a,   11 /* Public */,
      10,    1,   74,    2, 0x0a,   13 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,   11,

       0        // eod
};

void s21::Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RotateAroundXAxis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->RotateAroundYAxis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->RotateAroundZAxis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ShiftOnXAxis((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->ShiftOnYAxis((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->ShiftOnZAxis((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->Scaling((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject s21::Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_s21__Controller.offsetsAndSize,
    qt_meta_data_s21__Controller,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__Controller_t
, QtPrivate::TypeAndForceComplete<Controller, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


>,
    nullptr
} };


const QMetaObject *s21::Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int s21::Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
