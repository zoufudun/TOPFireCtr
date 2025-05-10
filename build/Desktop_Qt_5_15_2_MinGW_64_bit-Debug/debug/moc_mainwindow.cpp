/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "newProject"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "openProject"
QT_MOC_LITERAL(4, 35, 11), // "saveProject"
QT_MOC_LITERAL(5, 47, 13), // "saveProjectAs"
QT_MOC_LITERAL(6, 61, 13), // "renameProject"
QT_MOC_LITERAL(7, 75, 12), // "addComponent"
QT_MOC_LITERAL(8, 88, 15), // "deleteComponent"
QT_MOC_LITERAL(9, 104, 13), // "moveComponent"
QT_MOC_LITERAL(10, 118, 18), // "configureComponent"
QT_MOC_LITERAL(11, 137, 16), // "onComponentAdded"
QT_MOC_LITERAL(12, 154, 13), // "ComponentInfo"
QT_MOC_LITERAL(13, 168, 9), // "component"
QT_MOC_LITERAL(14, 178, 18), // "onComponentDeleted"
QT_MOC_LITERAL(15, 197, 14), // "QStandardItem*"
QT_MOC_LITERAL(16, 212, 4), // "item"
QT_MOC_LITERAL(17, 217, 16), // "onComponentMoved"
QT_MOC_LITERAL(18, 234, 9), // "newParent"
QT_MOC_LITERAL(19, 244, 21), // "onComponentConfigured"
QT_MOC_LITERAL(20, 266, 15), // "moveComponentUp"
QT_MOC_LITERAL(21, 282, 17), // "moveComponentDown"
QT_MOC_LITERAL(22, 300, 23), // "onComponentOrderChanged"
QT_MOC_LITERAL(23, 324, 6), // "parent"
QT_MOC_LITERAL(24, 331, 8), // "oldIndex"
QT_MOC_LITERAL(25, 340, 8) // "newIndex"

    },
    "MainWindow\0newProject\0\0openProject\0"
    "saveProject\0saveProjectAs\0renameProject\0"
    "addComponent\0deleteComponent\0moveComponent\0"
    "configureComponent\0onComponentAdded\0"
    "ComponentInfo\0component\0onComponentDeleted\0"
    "QStandardItem*\0item\0onComponentMoved\0"
    "newParent\0onComponentConfigured\0"
    "moveComponentUp\0moveComponentDown\0"
    "onComponentOrderChanged\0parent\0oldIndex\0"
    "newIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x08 /* Private */,
      14,    1,  106,    2, 0x08 /* Private */,
      17,    2,  109,    2, 0x08 /* Private */,
      19,    1,  114,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,
      21,    0,  118,    2, 0x08 /* Private */,
      22,    3,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15,   16,   18,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int, QMetaType::Int,   23,   24,   25,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newProject(); break;
        case 1: _t->openProject(); break;
        case 2: _t->saveProject(); break;
        case 3: _t->saveProjectAs(); break;
        case 4: _t->renameProject(); break;
        case 5: _t->addComponent(); break;
        case 6: _t->deleteComponent(); break;
        case 7: _t->moveComponent(); break;
        case 8: _t->configureComponent(); break;
        case 9: _t->onComponentAdded((*reinterpret_cast< const ComponentInfo(*)>(_a[1]))); break;
        case 10: _t->onComponentDeleted((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 11: _t->onComponentMoved((*reinterpret_cast< QStandardItem*(*)>(_a[1])),(*reinterpret_cast< QStandardItem*(*)>(_a[2]))); break;
        case 12: _t->onComponentConfigured((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 13: _t->moveComponentUp(); break;
        case 14: _t->moveComponentDown(); break;
        case 15: _t->onComponentOrderChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
