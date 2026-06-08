/****************************************************************************
** Meta object code from reading C++ file 'SenderBinUdp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/OCRdemo/SenderBinUdp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SenderBinUdp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SenderBinUdp_t {
    QByteArrayData data[9];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SenderBinUdp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SenderBinUdp_t qt_meta_stringdata_SenderBinUdp = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SenderBinUdp"
QT_MOC_LITERAL(1, 13, 8), // "progress"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "percent"
QT_MOC_LITERAL(4, 31, 8), // "finished"
QT_MOC_LITERAL(5, 40, 5), // "error"
QT_MOC_LITERAL(6, 46, 3), // "msg"
QT_MOC_LITERAL(7, 50, 8), // "stopSend"
QT_MOC_LITERAL(8, 59, 9) // "startSend"

    },
    "SenderBinUdp\0progress\0\0percent\0finished\0"
    "error\0msg\0stopSend\0startSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SenderBinUdp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,
       7,    0,   46,    2, 0x06 /* Public */,
       8,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SenderBinUdp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SenderBinUdp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->stopSend(); break;
        case 4: _t->startSend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SenderBinUdp::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SenderBinUdp::progress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SenderBinUdp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SenderBinUdp::finished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SenderBinUdp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SenderBinUdp::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SenderBinUdp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SenderBinUdp::stopSend)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SenderBinUdp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SenderBinUdp::startSend)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SenderBinUdp::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SenderBinUdp.data,
    qt_meta_data_SenderBinUdp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SenderBinUdp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SenderBinUdp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SenderBinUdp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SenderBinUdp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SenderBinUdp::progress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SenderBinUdp::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SenderBinUdp::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SenderBinUdp::stopSend()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SenderBinUdp::startSend()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
