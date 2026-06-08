/****************************************************************************
** Meta object code from reading C++ file 'qg_librarywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/qg_librarywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_librarywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_LibraryWidget_t {
    QByteArrayData data[23];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_LibraryWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_LibraryWidget_t qt_meta_stringdata_QG_LibraryWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QG_LibraryWidget"
QT_MOC_LITERAL(1, 17, 6), // "escape"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "setActionHandler"
QT_MOC_LITERAL(4, 42, 17), // "QG_ActionHandler*"
QT_MOC_LITERAL(5, 60, 2), // "ah"
QT_MOC_LITERAL(6, 63, 13), // "keyPressEvent"
QT_MOC_LITERAL(7, 77, 10), // "QKeyEvent*"
QT_MOC_LITERAL(8, 88, 1), // "e"
QT_MOC_LITERAL(9, 90, 6), // "insert"
QT_MOC_LITERAL(10, 97, 7), // "refresh"
QT_MOC_LITERAL(11, 105, 8), // "scanTree"
QT_MOC_LITERAL(12, 114, 9), // "buildTree"
QT_MOC_LITERAL(13, 124, 10), // "appendTree"
QT_MOC_LITERAL(14, 135, 14), // "QStandardItem*"
QT_MOC_LITERAL(15, 150, 4), // "item"
QT_MOC_LITERAL(16, 155, 9), // "directory"
QT_MOC_LITERAL(17, 165, 13), // "updatePreview"
QT_MOC_LITERAL(18, 179, 11), // "QModelIndex"
QT_MOC_LITERAL(19, 191, 3), // "idx"
QT_MOC_LITERAL(20, 195, 10), // "expandView"
QT_MOC_LITERAL(21, 206, 12), // "collapseView"
QT_MOC_LITERAL(22, 219, 14) // "languageChange"

    },
    "QG_LibraryWidget\0escape\0\0setActionHandler\0"
    "QG_ActionHandler*\0ah\0keyPressEvent\0"
    "QKeyEvent*\0e\0insert\0refresh\0scanTree\0"
    "buildTree\0appendTree\0QStandardItem*\0"
    "item\0directory\0updatePreview\0QModelIndex\0"
    "idx\0expandView\0collapseView\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_LibraryWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x0a /* Public */,
       6,    1,   78,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    2,   85,    2, 0x0a /* Public */,
      17,    1,   90,    2, 0x0a /* Public */,
      20,    1,   93,    2, 0x0a /* Public */,
      21,    1,   96,    2, 0x0a /* Public */,
      22,    0,   99,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QString,   15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,

       0        // eod
};

void QG_LibraryWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_LibraryWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->escape(); break;
        case 1: _t->setActionHandler((*reinterpret_cast< QG_ActionHandler*(*)>(_a[1]))); break;
        case 2: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->insert(); break;
        case 4: _t->refresh(); break;
        case 5: _t->scanTree(); break;
        case 6: _t->buildTree(); break;
        case 7: _t->appendTree((*reinterpret_cast< QStandardItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->updatePreview((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->expandView((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 10: _t->collapseView((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 11: _t->languageChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QG_LibraryWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QG_LibraryWidget::escape)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_LibraryWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_LibraryWidget.data,
    qt_meta_data_QG_LibraryWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_LibraryWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_LibraryWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_LibraryWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_LibraryWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QG_LibraryWidget::escape()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
