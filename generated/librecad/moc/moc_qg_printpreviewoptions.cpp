/****************************************************************************
** Meta object code from reading C++ file 'qg_printpreviewoptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_printpreviewoptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_printpreviewoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_PrintPreviewOptions_t {
    QByteArrayData data[22];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_PrintPreviewOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_PrintPreviewOptions_t qt_meta_stringdata_QG_PrintPreviewOptions = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QG_PrintPreviewOptions"
QT_MOC_LITERAL(1, 23, 9), // "setAction"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "RS_ActionInterface*"
QT_MOC_LITERAL(4, 54, 1), // "a"
QT_MOC_LITERAL(5, 56, 6), // "update"
QT_MOC_LITERAL(6, 63, 10), // "updateData"
QT_MOC_LITERAL(7, 74, 6), // "center"
QT_MOC_LITERAL(8, 81, 19), // "setLineWidthScaling"
QT_MOC_LITERAL(9, 101, 5), // "state"
QT_MOC_LITERAL(10, 107, 13), // "setBlackWhite"
QT_MOC_LITERAL(11, 121, 2), // "on"
QT_MOC_LITERAL(12, 124, 3), // "fit"
QT_MOC_LITERAL(13, 128, 5), // "scale"
QT_MOC_LITERAL(14, 134, 1), // "s"
QT_MOC_LITERAL(15, 136, 6), // "factor"
QT_MOC_LITERAL(16, 143, 14), // "updateScaleBox"
QT_MOC_LITERAL(17, 158, 1), // "f"
QT_MOC_LITERAL(18, 160, 13), // "setScaleFixed"
QT_MOC_LITERAL(19, 174, 5), // "fixed"
QT_MOC_LITERAL(20, 180, 12), // "calcPagesNum"
QT_MOC_LITERAL(21, 193, 14) // "languageChange"

    },
    "QG_PrintPreviewOptions\0setAction\0\0"
    "RS_ActionInterface*\0a\0update\0updateData\0"
    "center\0setLineWidthScaling\0state\0"
    "setBlackWhite\0on\0fit\0scale\0s\0factor\0"
    "updateScaleBox\0f\0setScaleFixed\0fixed\0"
    "calcPagesNum\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_PrintPreviewOptions[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x0a /* Public */,
       6,    0,   84,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x0a /* Public */,
       8,    1,   86,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    1,   93,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      16,    0,   99,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      18,    1,  103,    2, 0x0a /* Public */,
      20,    0,  106,    2, 0x0a /* Public */,
      21,    0,  107,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QG_PrintPreviewOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_PrintPreviewOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAction((*reinterpret_cast< RS_ActionInterface*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->updateData(); break;
        case 2: _t->center(); break;
        case 3: _t->setLineWidthScaling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setBlackWhite((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->fit(); break;
        case 6: _t->scale((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->scale((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 8: _t->updateScaleBox(); break;
        case 9: _t->updateScaleBox((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 10: _t->setScaleFixed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->calcPagesNum(); break;
        case 12: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_PrintPreviewOptions::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_PrintPreviewOptions.data,
    qt_meta_data_QG_PrintPreviewOptions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_PrintPreviewOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_PrintPreviewOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_PrintPreviewOptions.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_PrintPreviewOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
