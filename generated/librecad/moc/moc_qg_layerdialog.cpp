/****************************************************************************
** Meta object code from reading C++ file 'qg_layerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_layerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_layerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_LayerDialog_t {
    QByteArrayData data[15];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_LayerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_LayerDialog_t qt_meta_stringdata_QG_LayerDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QG_LayerDialog"
QT_MOC_LITERAL(1, 15, 8), // "setLayer"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "RS_Layer*"
QT_MOC_LITERAL(4, 35, 1), // "l"
QT_MOC_LITERAL(5, 37, 11), // "updateLayer"
QT_MOC_LITERAL(6, 49, 8), // "validate"
QT_MOC_LITERAL(7, 58, 12), // "setLayerList"
QT_MOC_LITERAL(8, 71, 13), // "RS_LayerList*"
QT_MOC_LITERAL(9, 85, 2), // "ll"
QT_MOC_LITERAL(10, 88, 12), // "setEditLayer"
QT_MOC_LITERAL(11, 101, 2), // "el"
QT_MOC_LITERAL(12, 104, 12), // "getQLineEdit"
QT_MOC_LITERAL(13, 117, 10), // "QLineEdit*"
QT_MOC_LITERAL(14, 128, 14) // "languageChange"

    },
    "QG_LayerDialog\0setLayer\0\0RS_Layer*\0l\0"
    "updateLayer\0validate\0setLayerList\0"
    "RS_LayerList*\0ll\0setEditLayer\0el\0"
    "getQLineEdit\0QLineEdit*\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_LayerDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
      10,    1,   57,    2, 0x0a /* Public */,
      12,    0,   60,    2, 0x0a /* Public */,
      14,    0,   61,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    0x80000000 | 13,
    QMetaType::Void,

       0        // eod
};

void QG_LayerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_LayerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setLayer((*reinterpret_cast< RS_Layer*(*)>(_a[1]))); break;
        case 1: _t->updateLayer(); break;
        case 2: _t->validate(); break;
        case 3: _t->setLayerList((*reinterpret_cast< RS_LayerList*(*)>(_a[1]))); break;
        case 4: _t->setEditLayer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { QLineEdit* _r = _t->getQLineEdit();
            if (_a[0]) *reinterpret_cast< QLineEdit**>(_a[0]) = std::move(_r); }  break;
        case 6: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_LayerDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_LayerDialog.data,
    qt_meta_data_QG_LayerDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_LayerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_LayerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_LayerDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_LayerDialog"))
        return static_cast< Ui::QG_LayerDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_LayerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
