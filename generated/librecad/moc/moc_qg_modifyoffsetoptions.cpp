/****************************************************************************
** Meta object code from reading C++ file 'qg_modifyoffsetoptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_modifyoffsetoptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_modifyoffsetoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_ModifyOffsetOptions_t {
    QByteArrayData data[8];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_ModifyOffsetOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_ModifyOffsetOptions_t qt_meta_stringdata_QG_ModifyOffsetOptions = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QG_ModifyOffsetOptions"
QT_MOC_LITERAL(1, 23, 10), // "updateDist"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 1), // "d"
QT_MOC_LITERAL(4, 37, 7), // "setDist"
QT_MOC_LITERAL(5, 45, 7), // "double&"
QT_MOC_LITERAL(6, 53, 7), // "initial"
QT_MOC_LITERAL(7, 61, 14) // "languageChange"

    },
    "QG_ModifyOffsetOptions\0updateDist\0\0d\0"
    "setDist\0double&\0initial\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_ModifyOffsetOptions[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    2,   37,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   45,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Bool,    3,    6,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void,

       0        // eod
};

void QG_ModifyOffsetOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_ModifyOffsetOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateDist((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setDist((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->setDist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_ModifyOffsetOptions::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_ModifyOffsetOptions.data,
    qt_meta_data_QG_ModifyOffsetOptions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_ModifyOffsetOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_ModifyOffsetOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_ModifyOffsetOptions.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_ModifyOffsetOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
