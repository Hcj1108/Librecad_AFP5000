/****************************************************************************
** Meta object code from reading C++ file 'qg_dlgscale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_dlgscale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_dlgscale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_DlgScale_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_DlgScale_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_DlgScale_t qt_meta_stringdata_QG_DlgScale = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QG_DlgScale"
QT_MOC_LITERAL(1, 12, 7), // "setData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "RS_ScaleData*"
QT_MOC_LITERAL(4, 35, 1), // "d"
QT_MOC_LITERAL(5, 37, 10), // "updateData"
QT_MOC_LITERAL(6, 48, 14), // "languageChange"
QT_MOC_LITERAL(7, 63, 22), // "on_cbIsotropic_toggled"
QT_MOC_LITERAL(8, 86, 7), // "checked"
QT_MOC_LITERAL(9, 94, 24), // "on_leFactorX_textChanged"
QT_MOC_LITERAL(10, 119, 4), // "arg1"
QT_MOC_LITERAL(11, 124, 24) // "on_leFactorY_textChanged"

    },
    "QG_DlgScale\0setData\0\0RS_ScaleData*\0d\0"
    "updateData\0languageChange\0"
    "on_cbIsotropic_toggled\0checked\0"
    "on_leFactorX_textChanged\0arg1\0"
    "on_leFactorY_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_DlgScale[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x09 /* Protected */,
       7,    1,   49,    2, 0x08 /* Private */,
       9,    1,   52,    2, 0x08 /* Private */,
      11,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void QG_DlgScale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_DlgScale *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setData((*reinterpret_cast< RS_ScaleData*(*)>(_a[1]))); break;
        case 1: _t->updateData(); break;
        case 2: _t->languageChange(); break;
        case 3: _t->on_cbIsotropic_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_leFactorX_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_leFactorY_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_DlgScale::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_DlgScale.data,
    qt_meta_data_QG_DlgScale,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_DlgScale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_DlgScale::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_DlgScale.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_DlgScale"))
        return static_cast< Ui::QG_DlgScale*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_DlgScale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
