/****************************************************************************
** Meta object code from reading C++ file 'qg_blockdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_blockdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_blockdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_BlockDialog_t {
    QByteArrayData data[8];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_BlockDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_BlockDialog_t qt_meta_stringdata_QG_BlockDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QG_BlockDialog"
QT_MOC_LITERAL(1, 15, 12), // "setBlockList"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "RS_BlockList*"
QT_MOC_LITERAL(4, 43, 1), // "l"
QT_MOC_LITERAL(5, 45, 8), // "validate"
QT_MOC_LITERAL(6, 54, 6), // "cancel"
QT_MOC_LITERAL(7, 61, 14) // "languageChange"

    },
    "QG_BlockDialog\0setBlockList\0\0RS_BlockList*\0"
    "l\0validate\0cancel\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_BlockDialog[] = {

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
       5,    0,   37,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QG_BlockDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_BlockDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setBlockList((*reinterpret_cast< RS_BlockList*(*)>(_a[1]))); break;
        case 1: _t->validate(); break;
        case 2: _t->cancel(); break;
        case 3: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_BlockDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_BlockDialog.data,
    qt_meta_data_QG_BlockDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_BlockDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_BlockDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_BlockDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_BlockDialog"))
        return static_cast< Ui::QG_BlockDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_BlockDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
