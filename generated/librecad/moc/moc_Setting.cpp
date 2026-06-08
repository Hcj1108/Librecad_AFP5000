/****************************************************************************
** Meta object code from reading C++ file 'Setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/OCRdemo/Setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Setting_t {
    QByteArrayData data[15];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Setting_t qt_meta_stringdata_Setting = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Setting"
QT_MOC_LITERAL(1, 8, 12), // "closeautocap"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "showmain"
QT_MOC_LITERAL(4, 31, 9), // "firstopen"
QT_MOC_LITERAL(5, 41, 7), // "autocap"
QT_MOC_LITERAL(6, 49, 7), // "getrect"
QT_MOC_LITERAL(7, 57, 15), // "setExposureTime"
QT_MOC_LITERAL(8, 73, 12), // "setGainValue"
QT_MOC_LITERAL(9, 86, 6), // "setRot"
QT_MOC_LITERAL(10, 93, 11), // "setCapAlarm"
QT_MOC_LITERAL(11, 105, 12), // "setSharpness"
QT_MOC_LITERAL(12, 118, 7), // "viewlog"
QT_MOC_LITERAL(13, 126, 9), // "updatapsw"
QT_MOC_LITERAL(14, 136, 9) // "caponepic"

    },
    "Setting\0closeautocap\0\0showmain\0firstopen\0"
    "autocap\0getrect\0setExposureTime\0"
    "setGainValue\0setRot\0setCapAlarm\0"
    "setSharpness\0viewlog\0updatapsw\0caponepic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Setting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,
       9,    0,   86,    2, 0x06 /* Public */,
      10,    0,   87,    2, 0x06 /* Public */,
      11,    0,   88,    2, 0x06 /* Public */,
      12,    0,   89,    2, 0x06 /* Public */,
      13,    0,   90,    2, 0x06 /* Public */,
      14,    0,   91,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeautocap(); break;
        case 1: _t->showmain(); break;
        case 2: _t->firstopen(); break;
        case 3: _t->autocap(); break;
        case 4: _t->getrect(); break;
        case 5: _t->setExposureTime(); break;
        case 6: _t->setGainValue(); break;
        case 7: _t->setRot(); break;
        case 8: _t->setCapAlarm(); break;
        case 9: _t->setSharpness(); break;
        case 10: _t->viewlog(); break;
        case 11: _t->updatapsw(); break;
        case 12: _t->caponepic(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::closeautocap)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::showmain)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::firstopen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::autocap)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::getrect)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::setExposureTime)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::setGainValue)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::setRot)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::setCapAlarm)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::setSharpness)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::viewlog)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::updatapsw)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Setting::caponepic)) {
                *result = 12;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Setting::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Setting.data,
    qt_meta_data_Setting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Setting.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Setting::closeautocap()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Setting::showmain()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Setting::firstopen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Setting::autocap()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Setting::getrect()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Setting::setExposureTime()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Setting::setGainValue()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Setting::setRot()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Setting::setCapAlarm()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Setting::setSharpness()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Setting::viewlog()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Setting::updatapsw()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Setting::caponepic()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
