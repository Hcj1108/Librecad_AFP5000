/****************************************************************************
** Meta object code from reading C++ file 'qg_pentoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/qg_pentoolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_pentoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_PenToolBar_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_PenToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_PenToolBar_t qt_meta_stringdata_QG_PenToolBar = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QG_PenToolBar"
QT_MOC_LITERAL(1, 14, 10), // "penChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "RS_Pen"
QT_MOC_LITERAL(4, 33, 16), // "slotColorChanged"
QT_MOC_LITERAL(5, 50, 8), // "RS_Color"
QT_MOC_LITERAL(6, 59, 5), // "color"
QT_MOC_LITERAL(7, 65, 16), // "slotWidthChanged"
QT_MOC_LITERAL(8, 82, 14), // "RS2::LineWidth"
QT_MOC_LITERAL(9, 97, 1), // "w"
QT_MOC_LITERAL(10, 99, 19), // "slotLineTypeChanged"
QT_MOC_LITERAL(11, 119, 13) // "RS2::LineType"

    },
    "QG_PenToolBar\0penChanged\0\0RS_Pen\0"
    "slotColorChanged\0RS_Color\0color\0"
    "slotWidthChanged\0RS2::LineWidth\0w\0"
    "slotLineTypeChanged\0RS2::LineType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_PenToolBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
      10,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,

       0        // eod
};

void QG_PenToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_PenToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->penChanged((*reinterpret_cast< RS_Pen(*)>(_a[1]))); break;
        case 1: _t->slotColorChanged((*reinterpret_cast< const RS_Color(*)>(_a[1]))); break;
        case 2: _t->slotWidthChanged((*reinterpret_cast< RS2::LineWidth(*)>(_a[1]))); break;
        case 3: _t->slotLineTypeChanged((*reinterpret_cast< RS2::LineType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QG_PenToolBar::*)(RS_Pen );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_PenToolBar::penChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_PenToolBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QToolBar::staticMetaObject>(),
    qt_meta_stringdata_QG_PenToolBar.data,
    qt_meta_data_QG_PenToolBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_PenToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_PenToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_PenToolBar.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RS_LayerListListener"))
        return static_cast< RS_LayerListListener*>(this);
    return QToolBar::qt_metacast(_clname);
}

int QG_PenToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QG_PenToolBar::penChanged(RS_Pen _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
