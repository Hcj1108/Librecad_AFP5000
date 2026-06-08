/****************************************************************************
** Meta object code from reading C++ file 'qg_polylineoptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_polylineoptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_polylineoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_PolylineOptions_t {
    QByteArrayData data[15];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_PolylineOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_PolylineOptions_t qt_meta_stringdata_QG_PolylineOptions = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QG_PolylineOptions"
QT_MOC_LITERAL(1, 19, 9), // "setAction"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "RS_ActionInterface*"
QT_MOC_LITERAL(4, 50, 1), // "a"
QT_MOC_LITERAL(5, 52, 6), // "update"
QT_MOC_LITERAL(6, 59, 5), // "close"
QT_MOC_LITERAL(7, 65, 4), // "undo"
QT_MOC_LITERAL(8, 70, 12), // "updateRadius"
QT_MOC_LITERAL(9, 83, 1), // "s"
QT_MOC_LITERAL(10, 85, 11), // "updateAngle"
QT_MOC_LITERAL(11, 97, 15), // "updateDirection"
QT_MOC_LITERAL(12, 113, 10), // "updateMode"
QT_MOC_LITERAL(13, 124, 1), // "m"
QT_MOC_LITERAL(14, 126, 14) // "languageChange"

    },
    "QG_PolylineOptions\0setAction\0\0"
    "RS_ActionInterface*\0a\0update\0close\0"
    "undo\0updateRadius\0s\0updateAngle\0"
    "updateDirection\0updateMode\0m\0"
    "languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_PolylineOptions[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,
      12,    1,   70,    2, 0x0a /* Public */,
      14,    0,   73,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void QG_PolylineOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_PolylineOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAction((*reinterpret_cast< RS_ActionInterface*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->close(); break;
        case 2: _t->undo(); break;
        case 3: _t->updateRadius((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->updateAngle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->updateDirection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->updateMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_PolylineOptions::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_PolylineOptions.data,
    qt_meta_data_QG_PolylineOptions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_PolylineOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_PolylineOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_PolylineOptions.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_PolylineOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
