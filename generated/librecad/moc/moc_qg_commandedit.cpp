/****************************************************************************
** Meta object code from reading C++ file 'qg_commandedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/qg_commandedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_commandedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_CommandEdit_t {
    QByteArrayData data[14];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_CommandEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_CommandEdit_t qt_meta_stringdata_QG_CommandEdit = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QG_CommandEdit"
QT_MOC_LITERAL(1, 15, 10), // "tabPressed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "escape"
QT_MOC_LITERAL(4, 34, 7), // "focusIn"
QT_MOC_LITERAL(5, 42, 8), // "focusOut"
QT_MOC_LITERAL(6, 51, 20), // "clearCommandsHistory"
QT_MOC_LITERAL(7, 72, 7), // "command"
QT_MOC_LITERAL(8, 80, 3), // "cmd"
QT_MOC_LITERAL(9, 84, 7), // "message"
QT_MOC_LITERAL(10, 92, 3), // "msg"
QT_MOC_LITERAL(11, 96, 7), // "keycode"
QT_MOC_LITERAL(12, 104, 4), // "code"
QT_MOC_LITERAL(13, 109, 13) // "modifiedPaste"

    },
    "QG_CommandEdit\0tabPressed\0\0escape\0"
    "focusIn\0focusOut\0clearCommandsHistory\0"
    "command\0cmd\0message\0msg\0keycode\0code\0"
    "modifiedPaste"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_CommandEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    1,   64,    2, 0x06 /* Public */,
       9,    1,   67,    2, 0x06 /* Public */,
      11,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QG_CommandEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_CommandEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tabPressed(); break;
        case 1: _t->escape(); break;
        case 2: _t->focusIn(); break;
        case 3: _t->focusOut(); break;
        case 4: _t->clearCommandsHistory(); break;
        case 5: _t->command((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->keycode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->modifiedPaste(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QG_CommandEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::tabPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QG_CommandEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::escape)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QG_CommandEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::focusIn)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QG_CommandEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::focusOut)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QG_CommandEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::clearCommandsHistory)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QG_CommandEdit::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::command)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QG_CommandEdit::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::message)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QG_CommandEdit::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_CommandEdit::keycode)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_CommandEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QLineEdit::staticMetaObject>(),
    qt_meta_stringdata_QG_CommandEdit.data,
    qt_meta_data_QG_CommandEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_CommandEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_CommandEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_CommandEdit.stringdata0))
        return static_cast<void*>(this);
    return QLineEdit::qt_metacast(_clname);
}

int QG_CommandEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
void QG_CommandEdit::tabPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QG_CommandEdit::escape()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QG_CommandEdit::focusIn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QG_CommandEdit::focusOut()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QG_CommandEdit::clearCommandsHistory()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QG_CommandEdit::command(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QG_CommandEdit::message(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QG_CommandEdit::keycode(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
