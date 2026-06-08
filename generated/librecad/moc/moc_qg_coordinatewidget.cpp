/****************************************************************************
** Meta object code from reading C++ file 'qg_coordinatewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_coordinatewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_coordinatewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_CoordinateWidget_t {
    QByteArrayData data[15];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_CoordinateWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_CoordinateWidget_t qt_meta_stringdata_QG_CoordinateWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QG_CoordinateWidget"
QT_MOC_LITERAL(1, 20, 10), // "setGraphic"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "RS_Graphic*"
QT_MOC_LITERAL(4, 44, 7), // "graphic"
QT_MOC_LITERAL(5, 52, 14), // "setCoordinates"
QT_MOC_LITERAL(6, 67, 9), // "RS_Vector"
QT_MOC_LITERAL(7, 77, 3), // "abs"
QT_MOC_LITERAL(8, 81, 3), // "rel"
QT_MOC_LITERAL(9, 85, 12), // "updateFormat"
QT_MOC_LITERAL(10, 98, 1), // "x"
QT_MOC_LITERAL(11, 100, 1), // "y"
QT_MOC_LITERAL(12, 102, 2), // "rx"
QT_MOC_LITERAL(13, 105, 2), // "ry"
QT_MOC_LITERAL(14, 108, 14) // "languageChange"

    },
    "QG_CoordinateWidget\0setGraphic\0\0"
    "RS_Graphic*\0graphic\0setCoordinates\0"
    "RS_Vector\0abs\0rel\0updateFormat\0x\0y\0"
    "rx\0ry\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_CoordinateWidget[] = {

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
       5,    3,   37,    2, 0x0a /* Public */,
       5,    5,   44,    2, 0x0a /* Public */,
      14,    0,   55,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6, QMetaType::Bool,    7,    8,    9,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   10,   11,   12,   13,    9,
    QMetaType::Void,

       0        // eod
};

void QG_CoordinateWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_CoordinateWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGraphic((*reinterpret_cast< RS_Graphic*(*)>(_a[1]))); break;
        case 1: _t->setCoordinates((*reinterpret_cast< const RS_Vector(*)>(_a[1])),(*reinterpret_cast< const RS_Vector(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->setCoordinates((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 3: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_CoordinateWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_CoordinateWidget.data,
    qt_meta_data_QG_CoordinateWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_CoordinateWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_CoordinateWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_CoordinateWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_CoordinateWidget"))
        return static_cast< Ui::QG_CoordinateWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_CoordinateWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
