/****************************************************************************
** Meta object code from reading C++ file 'browserapplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../browserapplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browserapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BrowserApplication_t {
    QByteArrayData data[9];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_BrowserApplication_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_BrowserApplication_t qt_meta_stringdata_BrowserApplication = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 13),
QT_MOC_LITERAL(2, 33, 18),
QT_MOC_LITERAL(3, 52, 0),
QT_MOC_LITERAL(4, 53, 18),
QT_MOC_LITERAL(5, 72, 10),
QT_MOC_LITERAL(6, 83, 7),
QT_MOC_LITERAL(7, 91, 3),
QT_MOC_LITERAL(8, 95, 24)
    },
    "BrowserApplication\0newMainWindow\0"
    "BrowserMainWindow*\0\0restoreLastSession\0"
    "postLaunch\0openUrl\0url\0newLocalSocketConnection\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrowserApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    3, 0x0a,
       4,    0,   40,    3, 0x0a,
       5,    0,   41,    3, 0x08,
       6,    1,   42,    3, 0x08,
       8,    0,   45,    3, 0x08,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Void,

       0        // eod
};

void BrowserApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BrowserApplication *_t = static_cast<BrowserApplication *>(_o);
        switch (_id) {
        case 0: { BrowserMainWindow* _r = _t->newMainWindow();
            if (_a[0]) *reinterpret_cast< BrowserMainWindow**>(_a[0]) = _r; }  break;
        case 1: _t->restoreLastSession(); break;
        case 2: _t->postLaunch(); break;
        case 3: _t->openUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: _t->newLocalSocketConnection(); break;
        default: ;
        }
    }
}

const QMetaObject BrowserApplication::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_BrowserApplication.data,
      qt_meta_data_BrowserApplication,  qt_static_metacall, 0, 0}
};


const QMetaObject *BrowserApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrowserApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BrowserApplication.stringdata))
        return static_cast<void*>(const_cast< BrowserApplication*>(this));
    return QApplication::qt_metacast(_clname);
}

int BrowserApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
