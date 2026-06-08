/****************************************************************************
** Meta object code from reading C++ file 'OCRruning.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/OCRdemo/OCRruning.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OCRruning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OCRruning_t {
    QByteArrayData data[32];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OCRruning_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OCRruning_t qt_meta_stringdata_OCRruning = {
    {
QT_MOC_LITERAL(0, 0, 9), // "OCRruning"
QT_MOC_LITERAL(1, 10, 7), // "running"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 27, 5), // "image"
QT_MOC_LITERAL(5, 33, 3), // "rot"
QT_MOC_LITERAL(6, 37, 8), // "cv::Rect"
QT_MOC_LITERAL(7, 46, 5), // "rects"
QT_MOC_LITERAL(8, 52, 8), // "QString*"
QT_MOC_LITERAL(9, 61, 9), // "rawResult"
QT_MOC_LITERAL(10, 71, 10), // "rawResult2"
QT_MOC_LITERAL(11, 82, 8), // "time_str"
QT_MOC_LITERAL(12, 91, 4), // "int*"
QT_MOC_LITERAL(13, 96, 6), // "result"
QT_MOC_LITERAL(14, 103, 9), // "SCenabled"
QT_MOC_LITERAL(15, 113, 9), // "BZenabled"
QT_MOC_LITERAL(16, 123, 9), // "EWenabled"
QT_MOC_LITERAL(17, 133, 15), // "Start_Data_Time"
QT_MOC_LITERAL(18, 149, 9), // "Save_Time"
QT_MOC_LITERAL(19, 159, 2), // "FH"
QT_MOC_LITERAL(20, 162, 8), // "IsCustom"
QT_MOC_LITERAL(21, 171, 9), // "CustomStr"
QT_MOC_LITERAL(22, 181, 11), // "CustomStr_2"
QT_MOC_LITERAL(23, 193, 11), // "CustomStr_3"
QT_MOC_LITERAL(24, 205, 11), // "CustomStr_4"
QT_MOC_LITERAL(25, 217, 11), // "CustomStr_5"
QT_MOC_LITERAL(26, 229, 11), // "CustomStr_6"
QT_MOC_LITERAL(27, 241, 7), // "double*"
QT_MOC_LITERAL(28, 249, 8), // "ocr_time"
QT_MOC_LITERAL(29, 258, 12), // "FirstOCRSize"
QT_MOC_LITERAL(30, 271, 10), // "SecOCRSize"
QT_MOC_LITERAL(31, 282, 6) // "ocrend"

    },
    "OCRruning\0running\0\0cv::Mat\0image\0rot\0"
    "cv::Rect\0rects\0QString*\0rawResult\0"
    "rawResult2\0time_str\0int*\0result\0"
    "SCenabled\0BZenabled\0EWenabled\0"
    "Start_Data_Time\0Save_Time\0FH\0IsCustom\0"
    "CustomStr\0CustomStr_2\0CustomStr_3\0"
    "CustomStr_4\0CustomStr_5\0CustomStr_6\0"
    "double*\0ocr_time\0FirstOCRSize\0SecOCRSize\0"
    "ocrend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OCRruning[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,   23,   24,    2, 0x06 /* Public */,
      31,    0,   71,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 12, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 27, QMetaType::Double, QMetaType::Double,    4,    5,    7,    9,   10,   11,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   28,   29,   30,
    QMetaType::Void,

       0        // eod
};

void OCRruning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OCRruning *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->running((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< cv::Rect(*)>(_a[3])),(*reinterpret_cast< QString*(*)>(_a[4])),(*reinterpret_cast< QString*(*)>(_a[5])),(*reinterpret_cast< QString*(*)>(_a[6])),(*reinterpret_cast< int*(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< bool(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< QString(*)>(_a[17])),(*reinterpret_cast< QString(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< double*(*)>(_a[21])),(*reinterpret_cast< double(*)>(_a[22])),(*reinterpret_cast< double(*)>(_a[23]))); break;
        case 1: _t->ocrend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OCRruning::*)(cv::Mat , double , cv::Rect , QString * , QString * , QString * , int * , bool , bool , bool , QString , QString , QString , bool , QString , QString , QString , QString , QString , QString , double * , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OCRruning::running)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OCRruning::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OCRruning::ocrend)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OCRruning::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_OCRruning.data,
    qt_meta_data_OCRruning,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OCRruning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OCRruning::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OCRruning.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OCRruning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void OCRruning::running(cv::Mat _t1, double _t2, cv::Rect _t3, QString * _t4, QString * _t5, QString * _t6, int * _t7, bool _t8, bool _t9, bool _t10, QString _t11, QString _t12, QString _t13, bool _t14, QString _t15, QString _t16, QString _t17, QString _t18, QString _t19, QString _t20, double * _t21, double _t22, double _t23)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t18))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t19))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t20))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t21))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t22))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t23))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OCRruning::ocrend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
