/****************************************************************************
** Meta object code from reading C++ file 'qc_mdiwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/main/qc_mdiwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qc_mdiwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QC_MDIWindow_t {
    QByteArrayData data[20];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QC_MDIWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QC_MDIWindow_t qt_meta_stringdata_QC_MDIWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QC_MDIWindow"
QT_MOC_LITERAL(1, 13, 13), // "signalClosing"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "QC_MDIWindow*"
QT_MOC_LITERAL(4, 42, 14), // "slotPenChanged"
QT_MOC_LITERAL(5, 57, 6), // "RS_Pen"
QT_MOC_LITERAL(6, 64, 1), // "p"
QT_MOC_LITERAL(7, 66, 11), // "slotFileNew"
QT_MOC_LITERAL(8, 78, 19), // "slotFileNewTemplate"
QT_MOC_LITERAL(9, 98, 8), // "fileName"
QT_MOC_LITERAL(10, 107, 15), // "RS2::FormatType"
QT_MOC_LITERAL(11, 123, 4), // "type"
QT_MOC_LITERAL(12, 128, 12), // "slotFileOpen"
QT_MOC_LITERAL(13, 141, 12), // "slotFileSave"
QT_MOC_LITERAL(14, 154, 5), // "bool&"
QT_MOC_LITERAL(15, 160, 9), // "cancelled"
QT_MOC_LITERAL(16, 170, 10), // "isAutoSave"
QT_MOC_LITERAL(17, 181, 14), // "slotFileSaveAs"
QT_MOC_LITERAL(18, 196, 13), // "slotFilePrint"
QT_MOC_LITERAL(19, 210, 12) // "slotZoomAuto"

    },
    "QC_MDIWindow\0signalClosing\0\0QC_MDIWindow*\0"
    "slotPenChanged\0RS_Pen\0p\0slotFileNew\0"
    "slotFileNewTemplate\0fileName\0"
    "RS2::FormatType\0type\0slotFileOpen\0"
    "slotFileSave\0bool&\0cancelled\0isAutoSave\0"
    "slotFileSaveAs\0slotFilePrint\0slotZoomAuto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QC_MDIWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   67,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    2,   71,    2, 0x0a /* Public */,
      12,    2,   76,    2, 0x0a /* Public */,
      13,    2,   81,    2, 0x0a /* Public */,
      13,    1,   86,    2, 0x2a /* Public | MethodCloned */,
      17,    1,   89,    2, 0x0a /* Public */,
      18,    0,   92,    2, 0x0a /* Public */,
      19,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 10,    9,   11,
    QMetaType::Bool, 0x80000000 | 14, QMetaType::Bool,   15,   16,
    QMetaType::Bool, 0x80000000 | 14,   15,
    QMetaType::Bool, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QC_MDIWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QC_MDIWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalClosing((*reinterpret_cast< QC_MDIWindow*(*)>(_a[1]))); break;
        case 1: _t->slotPenChanged((*reinterpret_cast< const RS_Pen(*)>(_a[1]))); break;
        case 2: _t->slotFileNew(); break;
        case 3: { bool _r = _t->slotFileNewTemplate((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< RS2::FormatType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->slotFileOpen((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< RS2::FormatType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->slotFileSave((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->slotFileSave((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->slotFileSaveAs((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->slotFilePrint(); break;
        case 9: _t->slotZoomAuto(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QC_MDIWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QC_MDIWindow::*)(QC_MDIWindow * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QC_MDIWindow::signalClosing)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QC_MDIWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMdiSubWindow::staticMetaObject>(),
    qt_meta_stringdata_QC_MDIWindow.data,
    qt_meta_data_QC_MDIWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QC_MDIWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QC_MDIWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QC_MDIWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RS_LayerListListener"))
        return static_cast< RS_LayerListListener*>(this);
    if (!strcmp(_clname, "RS_BlockListListener"))
        return static_cast< RS_BlockListListener*>(this);
    return QMdiSubWindow::qt_metacast(_clname);
}

int QC_MDIWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QC_MDIWindow::signalClosing(QC_MDIWindow * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
