/****************************************************************************
** Meta object code from reading C++ file 'qg_arctangentialoptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_arctangentialoptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_arctangentialoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_ArcTangentialOptions_t {
    QByteArrayData data[17];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_ArcTangentialOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_ArcTangentialOptions_t qt_meta_stringdata_QG_ArcTangentialOptions = {
    {
QT_MOC_LITERAL(0, 0, 23), // "QG_ArcTangentialOptions"
QT_MOC_LITERAL(1, 24, 9), // "setAction"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "RS_ActionInterface*"
QT_MOC_LITERAL(4, 55, 1), // "a"
QT_MOC_LITERAL(5, 57, 6), // "update"
QT_MOC_LITERAL(6, 64, 12), // "updateRadius"
QT_MOC_LITERAL(7, 77, 1), // "s"
QT_MOC_LITERAL(8, 79, 11), // "updateAngle"
QT_MOC_LITERAL(9, 91, 14), // "updateByRadius"
QT_MOC_LITERAL(10, 106, 2), // "br"
QT_MOC_LITERAL(11, 109, 14), // "languageChange"
QT_MOC_LITERAL(12, 124, 27), // "on_leRadius_editingFinished"
QT_MOC_LITERAL(13, 152, 26), // "on_leAngle_editingFinished"
QT_MOC_LITERAL(14, 179, 19), // "on_rbRadius_clicked"
QT_MOC_LITERAL(15, 199, 7), // "checked"
QT_MOC_LITERAL(16, 207, 18) // "on_rbAngle_clicked"

    },
    "QG_ArcTangentialOptions\0setAction\0\0"
    "RS_ActionInterface*\0a\0update\0updateRadius\0"
    "s\0updateAngle\0updateByRadius\0br\0"
    "languageChange\0on_leRadius_editingFinished\0"
    "on_leAngle_editingFinished\0"
    "on_rbRadius_clicked\0checked\0"
    "on_rbAngle_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_ArcTangentialOptions[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x0a /* Public */,
       6,    1,   64,    2, 0x0a /* Public */,
       8,    1,   67,    2, 0x0a /* Public */,
       9,    1,   70,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x09 /* Protected */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,
      14,    1,   76,    2, 0x08 /* Private */,
      16,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,

       0        // eod
};

void QG_ArcTangentialOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_ArcTangentialOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAction((*reinterpret_cast< RS_ActionInterface*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->updateRadius((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateAngle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->updateByRadius((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->languageChange(); break;
        case 5: _t->on_leRadius_editingFinished(); break;
        case 6: _t->on_leAngle_editingFinished(); break;
        case 7: _t->on_rbRadius_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_rbAngle_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_ArcTangentialOptions::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_ArcTangentialOptions.data,
    qt_meta_data_QG_ArcTangentialOptions,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_ArcTangentialOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_ArcTangentialOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_ArcTangentialOptions.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_ArcTangentialOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
