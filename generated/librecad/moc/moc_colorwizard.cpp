/****************************************************************************
** Meta object code from reading C++ file 'colorwizard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/generic/colorwizard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorwizard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColorWizard_t {
    QByteArrayData data[13];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorWizard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorWizard_t qt_meta_stringdata_ColorWizard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ColorWizard"
QT_MOC_LITERAL(1, 12, 21), // "requestingColorChange"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "requestingSelection"
QT_MOC_LITERAL(4, 55, 18), // "colorDoubleClicked"
QT_MOC_LITERAL(5, 74, 18), // "requestColorChange"
QT_MOC_LITERAL(6, 93, 16), // "requestSelection"
QT_MOC_LITERAL(7, 110, 17), // "invokeColorDialog"
QT_MOC_LITERAL(8, 128, 11), // "addOrRemove"
QT_MOC_LITERAL(9, 140, 14), // "removeFavorite"
QT_MOC_LITERAL(10, 155, 17), // "handleDoubleClick"
QT_MOC_LITERAL(11, 173, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(12, 190, 4) // "item"

    },
    "ColorWizard\0requestingColorChange\0\0"
    "requestingSelection\0colorDoubleClicked\0"
    "requestColorChange\0requestSelection\0"
    "invokeColorDialog\0addOrRemove\0"
    "removeFavorite\0handleDoubleClick\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorWizard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   68,    2, 0x09 /* Protected */,
       6,    0,   69,    2, 0x09 /* Protected */,
       7,    0,   70,    2, 0x09 /* Protected */,
       8,    0,   71,    2, 0x09 /* Protected */,
       9,    0,   72,    2, 0x09 /* Protected */,
      10,    1,   73,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ColorWizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ColorWizard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestingColorChange((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->requestingSelection((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->colorDoubleClicked((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->requestColorChange(); break;
        case 4: _t->requestSelection(); break;
        case 5: _t->invokeColorDialog(); break;
        case 6: _t->addOrRemove(); break;
        case 7: _t->removeFavorite(); break;
        case 8: _t->handleDoubleClick((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ColorWizard::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorWizard::requestingColorChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ColorWizard::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorWizard::requestingSelection)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ColorWizard::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ColorWizard::colorDoubleClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ColorWizard::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_ColorWizard.data,
    qt_meta_data_ColorWizard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ColorWizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorWizard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColorWizard.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int ColorWizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ColorWizard::requestingColorChange(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ColorWizard::requestingSelection(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ColorWizard::colorDoubleClicked(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
