/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/OCRdemo/user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_user_t {
    QByteArrayData data[12];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_user_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_user_t qt_meta_stringdata_user = {
    {
QT_MOC_LITERAL(0, 0, 4), // "user"
QT_MOC_LITERAL(1, 5, 8), // "showmain"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 7), // "addUser"
QT_MOC_LITERAL(4, 23, 7), // "delUser"
QT_MOC_LITERAL(5, 31, 10), // "SwitchUser"
QT_MOC_LITERAL(6, 42, 13), // "alterpassword"
QT_MOC_LITERAL(7, 56, 8), // "stopSend"
QT_MOC_LITERAL(8, 65, 9), // "startSend"
QT_MOC_LITERAL(9, 75, 23), // "usereraseCompleteSignal"
QT_MOC_LITERAL(10, 99, 23), // "userwriteCompleteSignal"
QT_MOC_LITERAL(11, 123, 22) // "userreadCompleteSignal"

    },
    "user\0showmain\0\0addUser\0delUser\0"
    "SwitchUser\0alterpassword\0stopSend\0"
    "startSend\0usereraseCompleteSignal\0"
    "userwriteCompleteSignal\0userreadCompleteSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_user[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    0,   70,    2, 0x06 /* Public */,
       9,    0,   71,    2, 0x06 /* Public */,
      10,    0,   72,    2, 0x06 /* Public */,
      11,    0,   73,    2, 0x06 /* Public */,

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

       0        // eod
};

void user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<user *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showmain(); break;
        case 1: _t->addUser(); break;
        case 2: _t->delUser(); break;
        case 3: _t->SwitchUser(); break;
        case 4: _t->alterpassword(); break;
        case 5: _t->stopSend(); break;
        case 6: _t->startSend(); break;
        case 7: _t->usereraseCompleteSignal(); break;
        case 8: _t->userwriteCompleteSignal(); break;
        case 9: _t->userreadCompleteSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::showmain)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::addUser)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::delUser)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::SwitchUser)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::alterpassword)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::stopSend)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::startSend)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::usereraseCompleteSignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::userwriteCompleteSignal)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::userreadCompleteSignal)) {
                *result = 9;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject user::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_user.data,
    qt_meta_data_user,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *user::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_user.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void user::showmain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void user::addUser()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void user::delUser()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void user::SwitchUser()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void user::alterpassword()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void user::stopSend()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void user::startSend()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void user::usereraseCompleteSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void user::userwriteCompleteSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void user::userreadCompleteSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
