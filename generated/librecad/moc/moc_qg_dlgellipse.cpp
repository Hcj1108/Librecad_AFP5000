/****************************************************************************
** Meta object code from reading C++ file 'qg_dlgellipse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_dlgellipse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_dlgellipse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_DlgEllipse_t {
    QByteArrayData data[7];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_DlgEllipse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_DlgEllipse_t qt_meta_stringdata_QG_DlgEllipse = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QG_DlgEllipse"
QT_MOC_LITERAL(1, 14, 10), // "setEllipse"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "RS_Ellipse&"
QT_MOC_LITERAL(4, 38, 1), // "e"
QT_MOC_LITERAL(5, 40, 13), // "updateEllipse"
QT_MOC_LITERAL(6, 54, 14) // "languageChange"

    },
    "QG_DlgEllipse\0setEllipse\0\0RS_Ellipse&\0"
    "e\0updateEllipse\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_DlgEllipse[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QG_DlgEllipse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_DlgEllipse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setEllipse((*reinterpret_cast< RS_Ellipse(*)>(_a[1]))); break;
        case 1: _t->updateEllipse(); break;
        case 2: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_DlgEllipse::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_DlgEllipse.data,
    qt_meta_data_QG_DlgEllipse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_DlgEllipse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_DlgEllipse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_DlgEllipse.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_DlgEllipse"))
        return static_cast< Ui::QG_DlgEllipse*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_DlgEllipse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
