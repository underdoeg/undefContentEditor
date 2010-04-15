/****************************************************************************
** Meta object code from reading C++ file 'api.h'
**
** Created: Thu Apr 15 04:21:07 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "utils/api.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'api.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerAPI[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   11,   10,   10, 0x08,
      59,   11,   10,   10, 0x08,
      93,   11,   10,   10, 0x08,
     127,   11,   10,   10, 0x08,
     162,   11,   10,   10, 0x08,
     227,  195,   10,   10, 0x08,
     278,  257,   10,   10, 0x08,
     336,  320,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerAPI[] = {
    "ServerAPI\0\0requestId,value\0"
    "respondGetPageIDs(int,QVariant)\0"
    "respondGetFieldData(int,QVariant)\0"
    "respondSavePageData(int,QVariant)\0"
    "respondSaveFieldData(int,QVariant)\0"
    "respondGetPageData(int,QVariant)\0"
    "requestId,errorCode,errorString\0"
    "processFault(int,int,QString)\0"
    "readBytes,totalBytes\0"
    "updateDataTransferProgress(qint64,qint64)\0"
    "commandId,error\0ftpCommandFinished(int,bool)\0"
};

const QMetaObject ServerAPI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ServerAPI,
      qt_meta_data_ServerAPI, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerAPI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerAPI))
        return static_cast<void*>(const_cast< ServerAPI*>(this));
    return QWidget::qt_metacast(_clname);
}

int ServerAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: respondGetPageIDs((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 1: respondGetFieldData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 2: respondSavePageData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 3: respondSaveFieldData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 4: respondGetPageData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 5: processFault((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: updateDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 7: ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
