/****************************************************************************
** Meta object code from reading C++ file 'imageanalyzer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imageanalyzer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageanalyzer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageAnalyzer_t {
    QByteArrayData data[16];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ImageAnalyzer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ImageAnalyzer_t qt_meta_stringdata_ImageAnalyzer = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 16),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 14),
QT_MOC_LITERAL(4, 47, 9),
QT_MOC_LITERAL(5, 57, 5),
QT_MOC_LITERAL(6, 63, 13),
QT_MOC_LITERAL(7, 77, 4),
QT_MOC_LITERAL(8, 82, 11),
QT_MOC_LITERAL(9, 94, 14),
QT_MOC_LITERAL(10, 109, 14),
QT_MOC_LITERAL(11, 124, 14),
QT_MOC_LITERAL(12, 139, 4),
QT_MOC_LITERAL(13, 144, 3),
QT_MOC_LITERAL(14, 148, 5),
QT_MOC_LITERAL(15, 154, 4)
    },
    "ImageAnalyzer\0finishedAnalysis\0\0"
    "updateProgress\0completed\0total\0"
    "startAnalysis\0urls\0handleReply\0"
    "QNetworkReply*\0doneProcessing\0"
    "progressStatus\0busy\0red\0green\0blue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageAnalyzer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06,
       3,    2,   45,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   50,    2, 0x0a,
       8,    1,   53,    2, 0x08,
      10,    0,   56,    2, 0x08,
      11,    1,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // properties: name, type, flags
      12, QMetaType::Bool, 0x00095001,
      13, QMetaType::Float, 0x00095001,
      14, QMetaType::Float, 0x00095001,
      15, QMetaType::Float, 0x00095001,

       0        // eod
};

void ImageAnalyzer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageAnalyzer *_t = static_cast<ImageAnalyzer *>(_o);
        switch (_id) {
        case 0: _t->finishedAnalysis(); break;
        case 1: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->startAnalysis((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 3: _t->handleReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->doneProcessing(); break;
        case 5: _t->progressStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageAnalyzer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageAnalyzer::finishedAnalysis)) {
                *result = 0;
            }
        }
        {
            typedef void (ImageAnalyzer::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageAnalyzer::updateProgress)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ImageAnalyzer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageAnalyzer.data,
      qt_meta_data_ImageAnalyzer,  qt_static_metacall, 0, 0}
};


const QMetaObject *ImageAnalyzer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageAnalyzer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageAnalyzer.stringdata))
        return static_cast<void*>(const_cast< ImageAnalyzer*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageAnalyzer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isBusy(); break;
        case 1: *reinterpret_cast< float*>(_v) = lastRed(); break;
        case 2: *reinterpret_cast< float*>(_v) = lastGreen(); break;
        case 3: *reinterpret_cast< float*>(_v) = lastBlue(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ImageAnalyzer::finishedAnalysis()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ImageAnalyzer::updateProgress(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
