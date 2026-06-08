/****************************************************************************
** Meta object code from reading C++ file 'qg_dlgimageoptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_dlgimageoptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_dlgimageoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_ImageOptionsDialog_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_ImageOptionsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_ImageOptionsDialog_t qt_meta_stringdata_QG_ImageOptionsDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QG_ImageOptionsDialog"
QT_MOC_LITERAL(1, 22, 14), // "setGraphicSize"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "RS_Vector"
QT_MOC_LITERAL(4, 48, 1), // "s"
QT_MOC_LITERAL(5, 50, 2), // "ok"
QT_MOC_LITERAL(6, 53, 11), // "sizeChanged"
QT_MOC_LITERAL(7, 65, 17), // "resolutionChanged"
QT_MOC_LITERAL(8, 83, 18), // "sameBordersChanged"
QT_MOC_LITERAL(9, 102, 13), // "borderChanged"
QT_MOC_LITERAL(10, 116, 14) // "languageChange"

    },
    "QG_ImageOptionsDialog\0setGraphicSize\0"
    "\0RS_Vector\0s\0ok\0sizeChanged\0"
    "resolutionChanged\0sameBordersChanged\0"
    "borderChanged\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_ImageOptionsDialog[] = {

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
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QG_ImageOptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_ImageOptionsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setGraphicSize((*reinterpret_cast< const RS_Vector(*)>(_a[1]))); break;
        case 1: _t->ok(); break;
        case 2: _t->sizeChanged(); break;
        case 3: _t->resolutionChanged(); break;
        case 4: _t->sameBordersChanged(); break;
        case 5: _t->borderChanged(); break;
        case 6: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_ImageOptionsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_ImageOptionsDialog.data,
    qt_meta_data_QG_ImageOptionsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_ImageOptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_ImageOptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_ImageOptionsDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_ImageOptionsDialog"))
        return static_cast< Ui::QG_ImageOptionsDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_ImageOptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
