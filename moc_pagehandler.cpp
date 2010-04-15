/****************************************************************************
** Meta object code from reading C++ file 'pagehandler.h'
**
** Created: Thu Apr 15 04:37:21 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pagehandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pagehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pageHandler[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      25,   12,   12,   12, 0x0a,
      38,   35,   12,   12, 0x0a,
      56,   54,   12,   12, 0x0a,
      74,   12,   12,   12, 0x0a,
      87,   54,   12,   12, 0x0a,
     103,   35,   12,   12, 0x0a,
     117,   12,   12,   12, 0x0a,
     125,   35,   12,   12, 0x0a,
     142,   12,   12,   12, 0x2a,
     156,   35,   12,   12, 0x0a,
     170,   12,   12,   12, 0x2a,
     190,  181,   12,   12, 0x0a,
     204,   12,   12,   12, 0x2a,
     215,   12,   12,   12, 0x0a,
     226,   12,   12,   12, 0x0a,
     252,   12,   12,   12, 0x0a,
     269,   12,   12,   12, 0x0a,
     294,   12,   12,   12, 0x0a,
     328,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pageHandler[] = {
    "pageHandler\0\0loadPages()\0addPage()\0"
    "id\0removePage(int)\0p\0removePage(page*)\0"
    "updateTree()\0showPage(page*)\0showPage(int)\0"
    "setup()\0loadPreview(int)\0loadPreview()\0"
    "savePage(int)\0savePage()\0parentID\0"
    "addField(int)\0addField()\0addImage()\0"
    "setFieldBackgroundColor()\0toggleTextEdit()\0"
    "setPageBackgroundColor()\0"
    "treeItemClicked(QTreeWidgetItem*)\0"
    "treeItemDoubleClicked(QTreeWidgetItem*)\0"
};

const QMetaObject pageHandler::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pageHandler,
      qt_meta_data_pageHandler, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pageHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pageHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pageHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pageHandler))
        return static_cast<void*>(const_cast< pageHandler*>(this));
    if (!strcmp(_clname, "apiListener"))
        return static_cast< apiListener*>(const_cast< pageHandler*>(this));
    return QWidget::qt_metacast(_clname);
}

int pageHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadPages(); break;
        case 1: addPage(); break;
        case 2: removePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: removePage((*reinterpret_cast< page*(*)>(_a[1]))); break;
        case 4: updateTree(); break;
        case 5: showPage((*reinterpret_cast< page*(*)>(_a[1]))); break;
        case 6: showPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: setup(); break;
        case 8: loadPreview((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: loadPreview(); break;
        case 10: savePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: savePage(); break;
        case 12: addField((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: addField(); break;
        case 14: addImage(); break;
        case 15: setFieldBackgroundColor(); break;
        case 16: toggleTextEdit(); break;
        case 17: setPageBackgroundColor(); break;
        case 18: treeItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 19: treeItemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
