<<<<<<< HEAD
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: PhodonZou
 * @Date: 2025-05-07 11:48:40
 * @LastEditors: PhodonZou
 * @LastEditTime: 2025-05-07 19:20:55
 */
=======
>>>>>>> 9bd960c (V0.1)
#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <QObject>
<<<<<<< HEAD
#include <QString>
#include <QList>
#include <QStandardItem>
#include "dimodule.h"  // 添加DI模块头文件
#include "domodule.h"  // 添加DO模块头文件

// 组件信息结构体
// 添加通信方式枚举
enum CommunicationType {
    TCP,
    UDP,
    CAN,
    MODBUS_485,
    ETHERCAT
};

// 在ComponentInfo结构体中添加通信方式字段
struct ComponentInfo {
    QString name;
    QString type;
    QString iconPath;
    int level;
    CommunicationType communicationType; // 添加通信方式
    QString description;
=======
#include <QList>
#include <QString>
#include <QStandardItem>

// 组件信息结构
struct ComponentInfo {
    QString name;        // 组件名称
    QString type;        // 组件类型
    QString description; // 组件描述
    int level;           // 组件层级 (1: 主机模块, 2: 其他模块)
>>>>>>> 9bd960c (V0.1)
};

class ComponentManager : public QObject
{
    Q_OBJECT

public:
    explicit ComponentManager(QObject *parent = nullptr);
    ~ComponentManager();

    void showAddComponentDialog();
<<<<<<< HEAD
    void showConfigureComponentDialog(QStandardItem *item = nullptr);
    void showDeleteComponentDialog(QStandardItem *item);
    void showMoveComponentDialog(QStandardItem *item);
    void moveComponentUp(QStandardItem *item);
    void moveComponentDown(QStandardItem *item);
    // 添加DI模块配置对话框
    void showDIModuleConfigDialog(QStandardItem *item);
    
    // 添加DO模块配置对话框
    void showDOModuleConfigDialog(QStandardItem *item);
=======
    void showConfigureComponentDialog();
    void showDeleteComponentDialog(QStandardItem *item); // 添加删除组件的对话框
    void showMoveComponentDialog(QStandardItem *item);   // 添加移动组件的对话框
>>>>>>> 9bd960c (V0.1)
    QList<ComponentInfo> getComponentTypes() const;

signals:
    void componentAdded(const ComponentInfo &component);
<<<<<<< HEAD
    void componentDeleted(QStandardItem *item);
    void componentMoved(QStandardItem *item, QStandardItem *newParent);
    void componentOrderChanged(QStandardItem *parent, int oldIndex, int newIndex);
    void componentConfigured(QStandardItem *item);  // Add this line
    void componentOrderChanged(QStandardItem *item, bool moveUp);
=======
    void componentDeleted(QStandardItem *item);          // 添加组件删除信号
    void componentMoved(QStandardItem *item, QStandardItem *newParent); // 添加组件移动信号
>>>>>>> 9bd960c (V0.1)

private:
    void initializeComponentTypes();
    QList<ComponentInfo> m_componentTypes;
<<<<<<< HEAD
    
    // 添加DI模块实例
    DIModule *m_diModule;
    
    // 添加DO模块实例
    DOModule *m_doModule;
=======
>>>>>>> 9bd960c (V0.1)
};

#endif // COMPONENTMANAGER_H
