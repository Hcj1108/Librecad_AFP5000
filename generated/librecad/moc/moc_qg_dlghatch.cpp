/****************************************************************************
** Meta object code from reading C++ file 'qg_dlghatch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_dlghatch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_dlghatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_DlgHatch_t {
    QByteArrayData data[17];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_DlgHatch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_DlgHatch_t qt_meta_stringdata_QG_DlgHatch = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QG_DlgHatch"
QT_MOC_LITERAL(1, 12, 6), // "polish"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "showEvent"
QT_MOC_LITERAL(4, 30, 11), // "QShowEvent*"
QT_MOC_LITERAL(5, 42, 1), // "e"
QT_MOC_LITERAL(6, 44, 8), // "setHatch"
QT_MOC_LITERAL(7, 53, 9), // "RS_Hatch&"
QT_MOC_LITERAL(8, 63, 1), // "h"
QT_MOC_LITERAL(9, 65, 5), // "isNew"
QT_MOC_LITERAL(10, 71, 11), // "updateHatch"
QT_MOC_LITERAL(11, 83, 10), // "setPattern"
QT_MOC_LITERAL(12, 94, 1), // "p"
QT_MOC_LITERAL(13, 96, 11), // "resizeEvent"
QT_MOC_LITERAL(14, 108, 13), // "QResizeEvent*"
QT_MOC_LITERAL(15, 122, 13), // "updatePreview"
QT_MOC_LITERAL(16, 136, 14) // "languageChange"

    },
    "QG_DlgHatch\0polish\0\0showEvent\0QShowEvent*\0"
    "e\0setHatch\0RS_Hatch&\0h\0isNew\0updateHatch\0"
    "setPattern\0p\0resizeEvent\0QResizeEvent*\0"
    "updatePreview\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_DlgHatch[] = {

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
       1,    0,   54,    2, 0x0a /* Public */,
       3,    1,   55,    2, 0x0a /* Public */,
       6,    2,   58,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,
      11,    1,   64,    2, 0x0a /* Public */,
      13,    1,   67,    2, 0x0a /* Public */,
      15,    0,   70,    2, 0x0a /* Public */,
      16,    0,   71,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QG_DlgHatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_DlgHatch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->polish(); break;
        case 1: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 2: _t->setHatch((*reinterpret_cast< RS_Hatch(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->updateHatch(); break;
        case 4: _t->setPattern((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 6: _t->updatePreview(); break;
        case 7: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_DlgHatch::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_DlgHatch.data,
    qt_meta_data_QG_DlgHatch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_DlgHatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_DlgHatch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_DlgHatch.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_DlgHatch"))
        return static_cast< Ui::QG_DlgHatch*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_DlgHatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
