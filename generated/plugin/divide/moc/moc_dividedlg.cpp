/****************************************************************************
** Meta object code from reading C++ file 'dividedlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../plugins/divide/dividedlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dividedlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dividedlg_t {
    QByteArrayData data[11];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dividedlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dividedlg_t qt_meta_stringdata_dividedlg = {
    {
QT_MOC_LITERAL(0, 0, 9), // "dividedlg"
QT_MOC_LITERAL(1, 10, 10), // "returnData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 17), // "onWhichButtonSlot"
QT_MOC_LITERAL(4, 40, 14), // "onOffTicksSlot"
QT_MOC_LITERAL(5, 55, 15), // "onOffBreaksSlot"
QT_MOC_LITERAL(6, 71, 17), // "onSizeChangedSlot"
QT_MOC_LITERAL(7, 89, 16), // "onQtyChangedSlot"
QT_MOC_LITERAL(8, 106, 23), // "onStartAngleChangedSlot"
QT_MOC_LITERAL(9, 130, 15), // "onOkClickedSlot"
QT_MOC_LITERAL(10, 146, 11) // "onInOutSlot"

    },
    "dividedlg\0returnData\0\0onWhichButtonSlot\0"
    "onOffTicksSlot\0onOffBreaksSlot\0"
    "onSizeChangedSlot\0onQtyChangedSlot\0"
    "onStartAngleChangedSlot\0onOkClickedSlot\0"
    "onInOutSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dividedlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   62,    2, 0x0a /* Public */,
       4,    1,   65,    2, 0x0a /* Public */,
       5,    1,   68,    2, 0x0a /* Public */,
       6,    1,   71,    2, 0x0a /* Public */,
       7,    1,   74,    2, 0x0a /* Public */,
       8,    1,   77,    2, 0x0a /* Public */,
       9,    0,   80,    2, 0x0a /* Public */,
      10,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void dividedlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dividedlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onWhichButtonSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onOffTicksSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onOffBreaksSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onSizeChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onQtyChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onStartAngleChangedSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onOkClickedSlot(); break;
        case 8: _t->onInOutSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dividedlg::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dividedlg::returnData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dividedlg::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_dividedlg.data,
    qt_meta_data_dividedlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dividedlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dividedlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dividedlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dividedlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void dividedlg::returnData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
