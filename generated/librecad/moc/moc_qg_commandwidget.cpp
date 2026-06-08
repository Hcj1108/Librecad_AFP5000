/****************************************************************************
** Meta object code from reading C++ file 'qg_commandwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_commandwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_commandwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_CommandWidget_t {
    QByteArrayData data[24];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_CommandWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_CommandWidget_t qt_meta_stringdata_QG_CommandWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QG_CommandWidget"
QT_MOC_LITERAL(1, 17, 8), // "setFocus"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "setCommand"
QT_MOC_LITERAL(4, 38, 3), // "cmd"
QT_MOC_LITERAL(5, 42, 13), // "appendHistory"
QT_MOC_LITERAL(6, 56, 3), // "msg"
QT_MOC_LITERAL(7, 60, 13), // "handleCommand"
QT_MOC_LITERAL(8, 74, 13), // "handleKeycode"
QT_MOC_LITERAL(9, 88, 4), // "code"
QT_MOC_LITERAL(10, 93, 10), // "tabPressed"
QT_MOC_LITERAL(11, 104, 6), // "escape"
QT_MOC_LITERAL(12, 111, 16), // "setActionHandler"
QT_MOC_LITERAL(13, 128, 17), // "QG_ActionHandler*"
QT_MOC_LITERAL(14, 146, 2), // "ah"
QT_MOC_LITERAL(15, 149, 14), // "setCommandMode"
QT_MOC_LITERAL(16, 164, 13), // "setNormalMode"
QT_MOC_LITERAL(17, 178, 14), // "getRootCommand"
QT_MOC_LITERAL(18, 193, 7), // "cmdList"
QT_MOC_LITERAL(19, 201, 5), // "typed"
QT_MOC_LITERAL(20, 207, 14), // "setKeycodeMode"
QT_MOC_LITERAL(21, 222, 5), // "state"
QT_MOC_LITERAL(22, 228, 14), // "languageChange"
QT_MOC_LITERAL(23, 243, 17) // "chooseCommandFile"

    },
    "QG_CommandWidget\0setFocus\0\0setCommand\0"
    "cmd\0appendHistory\0msg\0handleCommand\0"
    "handleKeycode\0code\0tabPressed\0escape\0"
    "setActionHandler\0QG_ActionHandler*\0"
    "ah\0setCommandMode\0setNormalMode\0"
    "getRootCommand\0cmdList\0typed\0"
    "setKeycodeMode\0state\0languageChange\0"
    "chooseCommandFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_CommandWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    1,   85,    2, 0x0a /* Public */,
       5,    1,   88,    2, 0x0a /* Public */,
       7,    1,   91,    2, 0x0a /* Public */,
       8,    1,   94,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    1,   99,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,
      17,    2,  104,    2, 0x0a /* Public */,
      20,    1,  109,    2, 0x0a /* Public */,
      22,    0,  112,    2, 0x09 /* Protected */,
      23,    0,  113,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QStringList, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QG_CommandWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_CommandWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFocus(); break;
        case 1: _t->setCommand((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->appendHistory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->handleCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->handleKeycode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->tabPressed(); break;
        case 6: _t->escape(); break;
        case 7: _t->setActionHandler((*reinterpret_cast< QG_ActionHandler*(*)>(_a[1]))); break;
        case 8: _t->setCommandMode(); break;
        case 9: _t->setNormalMode(); break;
        case 10: { QString _r = _t->getRootCommand((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setKeycodeMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->languageChange(); break;
        case 13: _t->chooseCommandFile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_CommandWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_CommandWidget.data,
    qt_meta_data_QG_CommandWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_CommandWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_CommandWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_CommandWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_CommandWidget"))
        return static_cast< Ui::QG_CommandWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_CommandWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
