/****************************************************************************
** Meta object code from reading C++ file 'qg_snaptoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_snaptoolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_snaptoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_SnapToolBar_t {
    QByteArrayData data[9];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_SnapToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_SnapToolBar_t qt_meta_stringdata_QG_SnapToolBar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QG_SnapToolBar"
QT_MOC_LITERAL(1, 15, 8), // "setSnaps"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "RS_SnapMode"
QT_MOC_LITERAL(4, 37, 1), // "s"
QT_MOC_LITERAL(5, 39, 15), // "actionTriggered"
QT_MOC_LITERAL(6, 55, 22), // "slotRestrictOrthogonal"
QT_MOC_LITERAL(7, 78, 7), // "checked"
QT_MOC_LITERAL(8, 86, 19) // "slotRestrictNothing"

    },
    "QG_SnapToolBar\0setSnaps\0\0RS_SnapMode\0"
    "s\0actionTriggered\0slotRestrictOrthogonal\0"
    "checked\0slotRestrictNothing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_SnapToolBar[] = {

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
       5,    0,   37,    2, 0x08 /* Private */,
       6,    1,   38,    2, 0x08 /* Private */,
       8,    1,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void QG_SnapToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_SnapToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSnaps((*reinterpret_cast< const RS_SnapMode(*)>(_a[1]))); break;
        case 1: _t->actionTriggered(); break;
        case 2: _t->slotRestrictOrthogonal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slotRestrictNothing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_SnapToolBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QToolBar::staticMetaObject>(),
    qt_meta_stringdata_QG_SnapToolBar.data,
    qt_meta_data_QG_SnapToolBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_SnapToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_SnapToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_SnapToolBar.stringdata0))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int QG_SnapToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
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
