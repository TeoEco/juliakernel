/****************************************************************************
** Meta object code from reading C++ file 'tabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabBar_t {
    QByteArrayData data[15];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TabBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TabBar_t qt_meta_stringdata_TabBar = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 6),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 8),
QT_MOC_LITERAL(4, 24, 5),
QT_MOC_LITERAL(5, 30, 8),
QT_MOC_LITERAL(6, 39, 14),
QT_MOC_LITERAL(7, 54, 9),
QT_MOC_LITERAL(8, 64, 13),
QT_MOC_LITERAL(9, 78, 16),
QT_MOC_LITERAL(10, 95, 9),
QT_MOC_LITERAL(11, 105, 7),
QT_MOC_LITERAL(12, 113, 15),
QT_MOC_LITERAL(13, 129, 20),
QT_MOC_LITERAL(14, 150, 8)
    },
    "TabBar\0newTab\0\0cloneTab\0index\0closeTab\0"
    "closeOtherTabs\0reloadTab\0reloadAllTabs\0"
    "tabMoveRequested\0fromIndex\0toIndex\0"
    "selectTabAction\0contextMenuRequested\0"
    "position\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06,
       3,    1,   80,    2, 0x06,
       5,    1,   83,    2, 0x06,
       6,    1,   86,    2, 0x06,
       7,    1,   89,    2, 0x06,
       8,    0,   92,    2, 0x06,
       9,    2,   93,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    0,   98,    2, 0x08,
       3,    0,   99,    2, 0x08,
       5,    0,  100,    2, 0x08,
       6,    0,  101,    2, 0x08,
       7,    0,  102,    2, 0x08,
      13,    1,  103,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   14,

       0        // eod
};

void TabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabBar *_t = static_cast<TabBar *>(_o);
        switch (_id) {
        case 0: _t->newTab(); break;
        case 1: _t->cloneTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->closeOtherTabs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->reloadTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->reloadAllTabs(); break;
        case 6: _t->tabMoveRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->selectTabAction(); break;
        case 8: _t->cloneTab(); break;
        case 9: _t->closeTab(); break;
        case 10: _t->closeOtherTabs(); break;
        case 11: _t->reloadTab(); break;
        case 12: _t->contextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TabBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabBar::newTab)) {
                *result = 0;
            }
        }
        {
            typedef void (TabBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabBar::cloneTab)) {
                *result = 1;
            }
        }
        {
            typedef void (TabBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabBar::closeTab)) {
                *result = 2;
            }
        }
        {
            typedef void (TabBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabBar::closeOtherTabs)) {
                *result = 3;
            }
        }
        {
            typedef void (TabBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabBar::reloadTab)) {
                *result = 4;
            }
        }
        {
            typedef void (TabBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabBar::reloadAllTabs)) {
                *result = 5;
            }
        }
        {
            typedef void (TabBar::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabBar::tabMoveRequested)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject TabBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_TabBar.data,
      qt_meta_data_TabBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *TabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabBar.stringdata))
        return static_cast<void*>(const_cast< TabBar*>(this));
    return QTabBar::qt_metacast(_clname);
}

int TabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TabBar::newTab()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TabBar::cloneTab(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TabBar::closeTab(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TabBar::closeOtherTabs(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TabBar::reloadTab(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TabBar::reloadAllTabs()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void TabBar::tabMoveRequested(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_WebActionMapper_t {
    QByteArrayData data[6];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WebActionMapper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WebActionMapper_t qt_meta_stringdata_WebActionMapper = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 13),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 12),
QT_MOC_LITERAL(4, 44, 13),
QT_MOC_LITERAL(5, 58, 16)
    },
    "WebActionMapper\0rootTriggered\0\0"
    "childChanged\0rootDestroyed\0currentDestroyed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebActionMapper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    0,   35,    2, 0x08,
       4,    0,   36,    2, 0x08,
       5,    0,   37,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WebActionMapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebActionMapper *_t = static_cast<WebActionMapper *>(_o);
        switch (_id) {
        case 0: _t->rootTriggered(); break;
        case 1: _t->childChanged(); break;
        case 2: _t->rootDestroyed(); break;
        case 3: _t->currentDestroyed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject WebActionMapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebActionMapper.data,
      qt_meta_data_WebActionMapper,  qt_static_metacall, 0, 0}
};


const QMetaObject *WebActionMapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebActionMapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebActionMapper.stringdata))
        return static_cast<void*>(const_cast< WebActionMapper*>(this));
    return QObject::qt_metacast(_clname);
}

int WebActionMapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_TabWidget_t {
    QByteArrayData data[49];
    char stringdata[681];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TabWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TabWidget_t qt_meta_stringdata_TabWidget = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 8),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 3),
QT_MOC_LITERAL(4, 24, 11),
QT_MOC_LITERAL(5, 36, 13),
QT_MOC_LITERAL(6, 50, 15),
QT_MOC_LITERAL(7, 66, 20),
QT_MOC_LITERAL(8, 87, 7),
QT_MOC_LITERAL(9, 95, 11),
QT_MOC_LITERAL(10, 107, 4),
QT_MOC_LITERAL(11, 112, 12),
QT_MOC_LITERAL(12, 125, 8),
QT_MOC_LITERAL(13, 134, 23),
QT_MOC_LITERAL(14, 158, 8),
QT_MOC_LITERAL(15, 167, 32),
QT_MOC_LITERAL(16, 200, 7),
QT_MOC_LITERAL(17, 208, 34),
QT_MOC_LITERAL(18, 243, 32),
QT_MOC_LITERAL(19, 276, 14),
QT_MOC_LITERAL(20, 291, 10),
QT_MOC_LITERAL(21, 302, 5),
QT_MOC_LITERAL(22, 308, 19),
QT_MOC_LITERAL(23, 328, 6),
QT_MOC_LITERAL(24, 335, 8),
QT_MOC_LITERAL(25, 344, 11),
QT_MOC_LITERAL(26, 356, 8),
QT_MOC_LITERAL(27, 365, 5),
QT_MOC_LITERAL(28, 371, 8),
QT_MOC_LITERAL(29, 380, 14),
QT_MOC_LITERAL(30, 395, 9),
QT_MOC_LITERAL(31, 405, 13),
QT_MOC_LITERAL(32, 419, 7),
QT_MOC_LITERAL(33, 427, 11),
QT_MOC_LITERAL(34, 439, 14),
QT_MOC_LITERAL(35, 454, 25),
QT_MOC_LITERAL(36, 480, 32),
QT_MOC_LITERAL(37, 513, 8),
QT_MOC_LITERAL(38, 522, 6),
QT_MOC_LITERAL(39, 529, 18),
QT_MOC_LITERAL(40, 548, 18),
QT_MOC_LITERAL(41, 567, 19),
QT_MOC_LITERAL(42, 587, 5),
QT_MOC_LITERAL(43, 593, 17),
QT_MOC_LITERAL(44, 611, 21),
QT_MOC_LITERAL(45, 633, 20),
QT_MOC_LITERAL(46, 654, 7),
QT_MOC_LITERAL(47, 662, 9),
QT_MOC_LITERAL(48, 672, 7)
    },
    "TabWidget\0loadPage\0\0url\0tabsChanged\0"
    "lastTabClosed\0setCurrentTitle\0"
    "showStatusBarMessage\0message\0linkHovered\0"
    "link\0loadProgress\0progress\0"
    "geometryChangeRequested\0geometry\0"
    "menuBarVisibilityChangeRequested\0"
    "visible\0statusBarVisibilityChangeRequested\0"
    "toolBarVisibilityChangeRequested\0"
    "printRequested\0QWebFrame*\0frame\0"
    "loadUrlInCurrentTab\0newTab\0WebView*\0"
    "makeCurrent\0cloneTab\0index\0closeTab\0"
    "closeOtherTabs\0reloadTab\0reloadAllTabs\0"
    "nextTab\0previousTab\0currentChanged\0"
    "aboutToShowRecentTabsMenu\0"
    "aboutToShowRecentTriggeredAction\0"
    "QAction*\0action\0webViewLoadStarted\0"
    "webViewIconChanged\0webViewTitleChanged\0"
    "title\0webViewUrlChanged\0lineEditReturnPressed\0"
    "windowCloseRequested\0moveTab\0fromIndex\0"
    "toIndex\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  189,    2, 0x06,
       4,    0,  192,    2, 0x06,
       5,    0,  193,    2, 0x06,
       6,    1,  194,    2, 0x06,
       7,    1,  197,    2, 0x06,
       9,    1,  200,    2, 0x06,
      11,    1,  203,    2, 0x06,
      13,    1,  206,    2, 0x06,
      15,    1,  209,    2, 0x06,
      17,    1,  212,    2, 0x06,
      18,    1,  215,    2, 0x06,
      19,    1,  218,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      22,    1,  221,    2, 0x0a,
      23,    1,  224,    2, 0x0a,
      23,    0,  227,    2, 0x2a,
      26,    1,  228,    2, 0x0a,
      26,    0,  231,    2, 0x2a,
      28,    1,  232,    2, 0x0a,
      28,    0,  235,    2, 0x2a,
      29,    1,  236,    2, 0x0a,
      30,    1,  239,    2, 0x0a,
      30,    0,  242,    2, 0x2a,
      31,    0,  243,    2, 0x0a,
      32,    0,  244,    2, 0x0a,
      33,    0,  245,    2, 0x0a,
      34,    1,  246,    2, 0x08,
      35,    0,  249,    2, 0x08,
      36,    1,  250,    2, 0x08,
      39,    0,  253,    2, 0x08,
      40,    0,  254,    2, 0x08,
      41,    1,  255,    2, 0x08,
      43,    1,  258,    2, 0x08,
      44,    0,  261,    2, 0x08,
      45,    0,  262,    2, 0x08,
      46,    2,  263,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QRect,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, 0x80000000 | 20,   21,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,    3,
    0x80000000 | 24, QMetaType::Bool,   25,
    0x80000000 | 24,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   47,   48,

       0        // eod
};

void TabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabWidget *_t = static_cast<TabWidget *>(_o);
        switch (_id) {
        case 0: _t->loadPage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->tabsChanged(); break;
        case 2: _t->lastTabClosed(); break;
        case 3: _t->setCurrentTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->showStatusBarMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->linkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->loadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->geometryChangeRequested((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 8: _t->menuBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->statusBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->toolBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->printRequested((*reinterpret_cast< QWebFrame*(*)>(_a[1]))); break;
        case 12: _t->loadUrlInCurrentTab((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 13: { WebView* _r = _t->newTab((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< WebView**>(_a[0]) = _r; }  break;
        case 14: { WebView* _r = _t->newTab();
            if (_a[0]) *reinterpret_cast< WebView**>(_a[0]) = _r; }  break;
        case 15: _t->cloneTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->cloneTab(); break;
        case 17: _t->closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->closeTab(); break;
        case 19: _t->closeOtherTabs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->reloadTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->reloadTab(); break;
        case 22: _t->reloadAllTabs(); break;
        case 23: _t->nextTab(); break;
        case 24: _t->previousTab(); break;
        case 25: _t->currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->aboutToShowRecentTabsMenu(); break;
        case 27: _t->aboutToShowRecentTriggeredAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 28: _t->webViewLoadStarted(); break;
        case 29: _t->webViewIconChanged(); break;
        case 30: _t->webViewTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->webViewUrlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 32: _t->lineEditReturnPressed(); break;
        case 33: _t->windowCloseRequested(); break;
        case 34: _t->moveTab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::loadPage)) {
                *result = 0;
            }
        }
        {
            typedef void (TabWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::tabsChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TabWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::lastTabClosed)) {
                *result = 2;
            }
        }
        {
            typedef void (TabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::setCurrentTitle)) {
                *result = 3;
            }
        }
        {
            typedef void (TabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::showStatusBarMessage)) {
                *result = 4;
            }
        }
        {
            typedef void (TabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::linkHovered)) {
                *result = 5;
            }
        }
        {
            typedef void (TabWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::loadProgress)) {
                *result = 6;
            }
        }
        {
            typedef void (TabWidget::*_t)(const QRect & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::geometryChangeRequested)) {
                *result = 7;
            }
        }
        {
            typedef void (TabWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::menuBarVisibilityChangeRequested)) {
                *result = 8;
            }
        }
        {
            typedef void (TabWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::statusBarVisibilityChangeRequested)) {
                *result = 9;
            }
        }
        {
            typedef void (TabWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::toolBarVisibilityChangeRequested)) {
                *result = 10;
            }
        }
        {
            typedef void (TabWidget::*_t)(QWebFrame * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabWidget::printRequested)) {
                *result = 11;
            }
        }
    }
}

const QMetaObject TabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_TabWidget.data,
      qt_meta_data_TabWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *TabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabWidget.stringdata))
        return static_cast<void*>(const_cast< TabWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int TabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void TabWidget::loadPage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TabWidget::tabsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TabWidget::lastTabClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void TabWidget::setCurrentTitle(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TabWidget::showStatusBarMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TabWidget::linkHovered(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TabWidget::loadProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TabWidget::geometryChangeRequested(const QRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TabWidget::menuBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TabWidget::statusBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TabWidget::toolBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void TabWidget::printRequested(QWebFrame * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
