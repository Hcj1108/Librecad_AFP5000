/****************************************************************************
** Meta object code from reading C++ file 'lc_simpletests.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/test/lc_simpletests.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lc_simpletests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LC_SimpleTests_t {
    QByteArrayData data[18];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LC_SimpleTests_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LC_SimpleTests_t qt_meta_stringdata_LC_SimpleTests = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LC_SimpleTests"
QT_MOC_LITERAL(1, 15, 20), // "slotTestDumpEntities"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "RS_EntityContainer*"
QT_MOC_LITERAL(4, 57, 1), // "d"
QT_MOC_LITERAL(5, 59, 16), // "slotTestDumpUndo"
QT_MOC_LITERAL(6, 76, 21), // "slotTestUpdateInserts"
QT_MOC_LITERAL(7, 98, 20), // "slotTestDrawFreehand"
QT_MOC_LITERAL(8, 119, 19), // "slotTestInsertBlock"
QT_MOC_LITERAL(9, 139, 21), // "slotTestInsertEllipse"
QT_MOC_LITERAL(10, 161, 19), // "slotTestInsertMText"
QT_MOC_LITERAL(11, 181, 18), // "slotTestInsertText"
QT_MOC_LITERAL(12, 200, 19), // "slotTestInsertImage"
QT_MOC_LITERAL(13, 220, 15), // "slotTestUnicode"
QT_MOC_LITERAL(14, 236, 14), // "slotTestMath01"
QT_MOC_LITERAL(15, 251, 17), // "slotTestResize640"
QT_MOC_LITERAL(16, 269, 17), // "slotTestResize800"
QT_MOC_LITERAL(17, 287, 18) // "slotTestResize1024"

    },
    "LC_SimpleTests\0slotTestDumpEntities\0"
    "\0RS_EntityContainer*\0d\0slotTestDumpUndo\0"
    "slotTestUpdateInserts\0slotTestDrawFreehand\0"
    "slotTestInsertBlock\0slotTestInsertEllipse\0"
    "slotTestInsertMText\0slotTestInsertText\0"
    "slotTestInsertImage\0slotTestUnicode\0"
    "slotTestMath01\0slotTestResize640\0"
    "slotTestResize800\0slotTestResize1024"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LC_SimpleTests[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       1,    0,   92,    2, 0x2a /* Public | MethodCloned */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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
    QMetaType::Void,

       0        // eod
};

void LC_SimpleTests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LC_SimpleTests *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotTestDumpEntities((*reinterpret_cast< RS_EntityContainer*(*)>(_a[1]))); break;
        case 1: _t->slotTestDumpEntities(); break;
        case 2: _t->slotTestDumpUndo(); break;
        case 3: _t->slotTestUpdateInserts(); break;
        case 4: _t->slotTestDrawFreehand(); break;
        case 5: _t->slotTestInsertBlock(); break;
        case 6: _t->slotTestInsertEllipse(); break;
        case 7: _t->slotTestInsertMText(); break;
        case 8: _t->slotTestInsertText(); break;
        case 9: _t->slotTestInsertImage(); break;
        case 10: _t->slotTestUnicode(); break;
        case 11: _t->slotTestMath01(); break;
        case 12: _t->slotTestResize640(); break;
        case 13: _t->slotTestResize800(); break;
        case 14: _t->slotTestResize1024(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LC_SimpleTests::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_LC_SimpleTests.data,
    qt_meta_data_LC_SimpleTests,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LC_SimpleTests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LC_SimpleTests::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LC_SimpleTests.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LC_SimpleTests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
