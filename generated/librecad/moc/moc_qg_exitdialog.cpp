/****************************************************************************
** Meta object code from reading C++ file 'qg_exitdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_exitdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_exitdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_ExitDialog_t {
    QByteArrayData data[15];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_ExitDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_ExitDialog_t qt_meta_stringdata_QG_ExitDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QG_ExitDialog"
QT_MOC_LITERAL(1, 14, 7), // "setText"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "text"
QT_MOC_LITERAL(4, 28, 8), // "setTitle"
QT_MOC_LITERAL(5, 37, 8), // "setForce"
QT_MOC_LITERAL(6, 46, 5), // "force"
QT_MOC_LITERAL(7, 52, 14), // "setShowSaveAll"
QT_MOC_LITERAL(8, 67, 4), // "show"
QT_MOC_LITERAL(9, 72, 11), // "slotSaveAll"
QT_MOC_LITERAL(10, 84, 8), // "slotSave"
QT_MOC_LITERAL(11, 93, 7), // "clicked"
QT_MOC_LITERAL(12, 101, 16), // "QAbstractButton*"
QT_MOC_LITERAL(13, 118, 6), // "button"
QT_MOC_LITERAL(14, 125, 14) // "languageChange"

    },
    "QG_ExitDialog\0setText\0\0text\0setTitle\0"
    "setForce\0force\0setShowSaveAll\0show\0"
    "slotSaveAll\0slotSave\0clicked\0"
    "QAbstractButton*\0button\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_ExitDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x0a /* Public */,
       5,    1,   60,    2, 0x0a /* Public */,
       7,    1,   63,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      14,    0,   71,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void QG_ExitDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_ExitDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setForce((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setShowSaveAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slotSaveAll(); break;
        case 5: _t->slotSave(); break;
        case 6: _t->clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 7: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_ExitDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_ExitDialog.data,
    qt_meta_data_QG_ExitDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_ExitDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_ExitDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_ExitDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_ExitDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
