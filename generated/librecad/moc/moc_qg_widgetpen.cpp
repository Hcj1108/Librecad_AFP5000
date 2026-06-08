/****************************************************************************
** Meta object code from reading C++ file 'qg_widgetpen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_widgetpen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_widgetpen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_WidgetPen_t {
    QByteArrayData data[10];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_WidgetPen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_WidgetPen_t qt_meta_stringdata_QG_WidgetPen = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QG_WidgetPen"
QT_MOC_LITERAL(1, 13, 6), // "setPen"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "RS_Pen"
QT_MOC_LITERAL(4, 28, 3), // "pen"
QT_MOC_LITERAL(5, 32, 11), // "showByLayer"
QT_MOC_LITERAL(6, 44, 13), // "showUnchanged"
QT_MOC_LITERAL(7, 58, 5), // "title"
QT_MOC_LITERAL(8, 64, 6), // "getPen"
QT_MOC_LITERAL(9, 71, 14) // "languageChange"

    },
    "QG_WidgetPen\0setPen\0\0RS_Pen\0pen\0"
    "showByLayer\0showUnchanged\0title\0getPen\0"
    "languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_WidgetPen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x0a /* Public */,
       8,    0,   38,    2, 0x0a /* Public */,
       9,    0,   39,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Bool, QMetaType::QString,    4,    5,    6,    7,
    0x80000000 | 3,
    QMetaType::Void,

       0        // eod
};

void QG_WidgetPen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_WidgetPen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPen((*reinterpret_cast< RS_Pen(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: { RS_Pen _r = _t->getPen();
            if (_a[0]) *reinterpret_cast< RS_Pen*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_WidgetPen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_WidgetPen.data,
    qt_meta_data_QG_WidgetPen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_WidgetPen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_WidgetPen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_WidgetPen.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_WidgetPen"))
        return static_cast< Ui::QG_WidgetPen*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_WidgetPen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
