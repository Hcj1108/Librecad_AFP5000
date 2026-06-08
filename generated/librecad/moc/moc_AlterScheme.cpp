/****************************************************************************
** Meta object code from reading C++ file 'AlterScheme.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/OCRdemo/AlterScheme.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlterScheme.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlterScheme_t {
    QByteArrayData data[17];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlterScheme_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlterScheme_t qt_meta_stringdata_AlterScheme = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AlterScheme"
QT_MOC_LITERAL(1, 12, 15), // "saveAlterScheme"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "deleteScheme"
QT_MOC_LITERAL(4, 42, 16), // "changeschemename"
QT_MOC_LITERAL(5, 59, 15), // "onCheckDCLength"
QT_MOC_LITERAL(6, 75, 24), // "onCheckOutputLocationMax"
QT_MOC_LITERAL(7, 100, 24), // "onCheckOutputLocationMin"
QT_MOC_LITERAL(8, 125, 21), // "onCheckWarnDelayCount"
QT_MOC_LITERAL(9, 147, 10), // "onCheckBZJ"
QT_MOC_LITERAL(10, 158, 27), // "onCheckDelayTriggerDistance"
QT_MOC_LITERAL(11, 186, 30), // "onCheckDelayTriggerDistancetwo"
QT_MOC_LITERAL(12, 217, 23), // "onCheckDelayTriggerTime"
QT_MOC_LITERAL(13, 241, 26), // "onCheckDelayTriggerTimetwo"
QT_MOC_LITERAL(14, 268, 6), // "onSave"
QT_MOC_LITERAL(15, 275, 7), // "onClose"
QT_MOC_LITERAL(16, 283, 8) // "onDelete"

    },
    "AlterScheme\0saveAlterScheme\0\0deleteScheme\0"
    "changeschemename\0onCheckDCLength\0"
    "onCheckOutputLocationMax\0"
    "onCheckOutputLocationMin\0onCheckWarnDelayCount\0"
    "onCheckBZJ\0onCheckDelayTriggerDistance\0"
    "onCheckDelayTriggerDistancetwo\0"
    "onCheckDelayTriggerTime\0"
    "onCheckDelayTriggerTimetwo\0onSave\0"
    "onClose\0onDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlterScheme[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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

void AlterScheme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AlterScheme *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveAlterScheme(); break;
        case 1: _t->deleteScheme(); break;
        case 2: _t->changeschemename(); break;
        case 3: _t->onCheckDCLength(); break;
        case 4: _t->onCheckOutputLocationMax(); break;
        case 5: _t->onCheckOutputLocationMin(); break;
        case 6: _t->onCheckWarnDelayCount(); break;
        case 7: _t->onCheckBZJ(); break;
        case 8: _t->onCheckDelayTriggerDistance(); break;
        case 9: _t->onCheckDelayTriggerDistancetwo(); break;
        case 10: _t->onCheckDelayTriggerTime(); break;
        case 11: _t->onCheckDelayTriggerTimetwo(); break;
        case 12: _t->onSave(); break;
        case 13: _t->onClose(); break;
        case 14: _t->onDelete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AlterScheme::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlterScheme::saveAlterScheme)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AlterScheme::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlterScheme::deleteScheme)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AlterScheme::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlterScheme::changeschemename)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AlterScheme::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AlterScheme.data,
    qt_meta_data_AlterScheme,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AlterScheme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlterScheme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlterScheme.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AlterScheme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void AlterScheme::saveAlterScheme()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AlterScheme::deleteScheme()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AlterScheme::changeschemename()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
