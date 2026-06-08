/****************************************************************************
** Meta object code from reading C++ file 'qg_dimensionlabeleditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/forms/qg_dimensionlabeleditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_dimensionlabeleditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_DimensionLabelEditor_t {
    QByteArrayData data[7];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_DimensionLabelEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_DimensionLabelEditor_t qt_meta_stringdata_QG_DimensionLabelEditor = {
    {
QT_MOC_LITERAL(0, 0, 23), // "QG_DimensionLabelEditor"
QT_MOC_LITERAL(1, 24, 8), // "setLabel"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 1), // "l"
QT_MOC_LITERAL(4, 36, 10), // "insertSign"
QT_MOC_LITERAL(5, 47, 1), // "s"
QT_MOC_LITERAL(6, 49, 14) // "languageChange"

    },
    "QG_DimensionLabelEditor\0setLabel\0\0l\0"
    "insertSign\0s\0languageChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_DimensionLabelEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void QG_DimensionLabelEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_DimensionLabelEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setLabel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->insertSign((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->languageChange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_DimensionLabelEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QG_DimensionLabelEditor.data,
    qt_meta_data_QG_DimensionLabelEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_DimensionLabelEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_DimensionLabelEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_DimensionLabelEditor.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::QG_DimensionLabelEditor"))
        return static_cast< Ui::QG_DimensionLabelEditor*>(this);
    return QWidget::qt_metacast(_clname);
}

int QG_DimensionLabelEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
