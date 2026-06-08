/****************************************************************************
** Meta object code from reading C++ file 'qg_dlgimage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_dlgimage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_dlgimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_DlgImage_t {
    QByteArrayData data[11];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_DlgImage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_DlgImage_t qt_meta_stringdata_QG_DlgImage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QG_DlgImage"
QT_MOC_LITERAL(1, 12, 8), // "setImage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "RS_Image&"
QT_MOC_LITERAL(4, 32, 1), // "e"
QT_MOC_LITERAL(5, 34, 11), // "changeWidth"
QT_MOC_LITERAL(6, 46, 12), // "changeHeight"
QT_MOC_LITERAL(7, 59, 11), // "changeScale"
QT_MOC_LITERAL(8, 71, 9), // "changeDPI"
QT_MOC_LITERAL(9, 81, 11), // "updateImage"
QT_MOC_LITERAL(10, 93, 14) // "languageChange"

    },
    "QG_DlgImage\0setImage\0\0RS_Image&\0e\0"
    "changeWidth\0changeHeight\0changeScale\0"
    "changeDPI\0updateImage\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_DlgImage[] = {

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

void QG_DlgImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_DlgImage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setImage((*reinterpret_cast< RS_Image(*)>(_a[1]))); break;
        case 1: _t->changeWidth(); break;
        case 2: _t->changeHeight(); break;
        case 3: _t->changeScale(); break;
        case 4: _t->changeDPI(); break;
        case 5: _t->updateImage(); break;
        case 6: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_DlgImage::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QG_DlgImage.data,
    qt_meta_data_QG_DlgImage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_DlgImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_DlgImage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_DlgImage.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_DlgImage"))
        return static_cast< Ui::QG_DlgImage*>(this);
    return QDialog::qt_metacast(_clname);
}

int QG_DlgImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
