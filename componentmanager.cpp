#include "componentmanager.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QTreeView>     // 添加此头文件
#include <QStandardItem> // 添加此头文件

<<<<<<< HEAD
<<<<<<< HEAD
#include "dimoduleconfigdialog.h"  // 添加DI模块配置对话框头文件
#include "domoduleconfigdialog.h"  // 添加DO模块配置对话框头文件

=======
>>>>>>> 9bd960c (V0.1)
=======
#include "dimoduleconfigdialog.h"  // 添加DI模块配置对话框头文件

>>>>>>> c7c6830 (增加DI模块配置界面)
ComponentManager::ComponentManager(QObject *parent)
    : QObject(parent)
{
    // 初始化组件类型列表
    initializeComponentTypes();
<<<<<<< HEAD
<<<<<<< HEAD
    
    // 初始化DI模块
    m_diModule = new DIModule(this);
    
    // 初始化DO模块
    m_doModule = new DOModule(this);
=======
>>>>>>> 9bd960c (V0.1)
=======
    
    // 初始化DI模块
    m_diModule = new DIModule(this);
>>>>>>> c7c6830 (增加DI模块配置界面)
}

ComponentManager::~ComponentManager()
{
}

void ComponentManager::initializeComponentTypes()
{
    // 定义组件类型及其层级关系
    // 第一层级 - 主机模块
    ComponentInfo hostModule;
    hostModule.name = "主机模块";
    hostModule.type = "HostModule";
    hostModule.description = "控制器主机模块";
    hostModule.level = 1;
<<<<<<< HEAD
<<<<<<< HEAD
    hostModule.iconPath = ":/icons/host.png";  // 设置图标路径
=======
>>>>>>> 9bd960c (V0.1)
=======
    hostModule.iconPath = ":/icons/host.png";  // 设置图标路径
>>>>>>> d0afa2c (组件实现双击添加)
    m_componentTypes.append(hostModule);
    
    // 第二层级 - 其他模块
    QStringList secondLevelModules = {
        "回路模块", "DI模块", "DO模块", "AI模块", "继电器模块", "通信模块"
    };
    
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> d0afa2c (组件实现双击添加)
    QStringList iconPaths = {
        ":/icons/loop.png", ":/icons/di.png", ":/icons/do.png", 
        ":/icons/ai.png", ":/icons/relay.png", ":/icons/comm.png"
    };
    
    for (int i = 0; i < secondLevelModules.size(); ++i) {
<<<<<<< HEAD
        ComponentInfo module;
        module.name = secondLevelModules[i];
        QString typeStr = secondLevelModules[i];
        module.type = typeStr.replace("模块", "Module");
        module.description = QString("%1，连接到主机模块").arg(secondLevelModules[i]);
        module.level = 2;
        module.iconPath = i < iconPaths.size() ? iconPaths[i] : ":/icons/default.png";
=======
    for (const QString &moduleName : secondLevelModules) {
=======
>>>>>>> d0afa2c (组件实现双击添加)
        ComponentInfo module;
        module.name = secondLevelModules[i];
        QString typeStr = secondLevelModules[i];
        module.type = typeStr.replace("模块", "Module");
        module.description = QString("%1，连接到主机模块").arg(secondLevelModules[i]);
        module.level = 2;
<<<<<<< HEAD
>>>>>>> 9bd960c (V0.1)
=======
        module.iconPath = i < iconPaths.size() ? iconPaths[i] : ":/icons/default.png";
>>>>>>> d0afa2c (组件实现双击添加)
        m_componentTypes.append(module);
    }
}

void ComponentManager::showAddComponentDialog()
{
    QDialog dialog;
<<<<<<< HEAD
    dialog.setWindowTitle(tr("添加组件"));
=======
    dialog.setWindowTitle("添加组件");
>>>>>>> 9bd960c (V0.1)
    dialog.setMinimumWidth(400);
    
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    
    QLabel *label = new QLabel("选择要添加的组件类型:");
    layout->addWidget(label);
    
    QListWidget *componentList = new QListWidget(&dialog);
    for (const ComponentInfo &component : m_componentTypes) {
        QListWidgetItem *item = new QListWidgetItem(component.name);
        item->setToolTip(component.description);
        item->setData(Qt::UserRole, component.type);
        item->setData(Qt::UserRole + 1, component.level);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> d0afa2c (组件实现双击添加)
        item->setData(Qt::UserRole + 2, component.iconPath);
        
        // 设置图标
        if (!component.iconPath.isEmpty()) {
            item->setIcon(QIcon(component.iconPath));
        }
        
<<<<<<< HEAD
=======
>>>>>>> 9bd960c (V0.1)
=======
>>>>>>> d0afa2c (组件实现双击添加)
        componentList->addItem(item);
    }
    layout->addWidget(componentList);
    
    // 添加组件命名输入框
    QHBoxLayout *nameLayout = new QHBoxLayout();
    QLabel *nameLabel = new QLabel("组件名称:");
    QLineEdit *nameEdit = new QLineEdit();
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);
    layout->addLayout(nameLayout);
    
    // 当选择组件时，自动填充默认名称
    connect(componentList, &QListWidget::currentItemChanged, [nameEdit, componentList](QListWidgetItem *current, QListWidgetItem *) {
        if (current) {
            nameEdit->setText(current->text());
            nameEdit->selectAll();
        }
    });
    
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> d0afa2c (组件实现双击添加)
    // 添加双击处理
    connect(componentList, &QListWidget::itemDoubleClicked, [&dialog](QListWidgetItem *) {
        dialog.accept();
    });
    
<<<<<<< HEAD
=======
>>>>>>> 9bd960c (V0.1)
=======
>>>>>>> d0afa2c (组件实现双击添加)
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    layout->addWidget(buttonBox);
    
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    
    // 如果没有选择组件，禁用确定按钮
    QPushButton *okButton = buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(false);
    connect(componentList, &QListWidget::currentItemChanged, [okButton](QListWidgetItem *current, QListWidgetItem *) {
        okButton->setEnabled(current != nullptr);
    });
    
    if (dialog.exec() == QDialog::Accepted) {
        QListWidgetItem *selectedItem = componentList->currentItem();
        if (selectedItem) {
            QString componentName = nameEdit->text().trimmed();
            if (componentName.isEmpty()) {
                componentName = selectedItem->text();
            }
            
            QString componentType = selectedItem->data(Qt::UserRole).toString();
            int componentLevel = selectedItem->data(Qt::UserRole + 1).toInt();
<<<<<<< HEAD
<<<<<<< HEAD
            QString iconPath = selectedItem->data(Qt::UserRole + 2).toString();
=======
>>>>>>> 9bd960c (V0.1)
=======
            QString iconPath = selectedItem->data(Qt::UserRole + 2).toString();
>>>>>>> d0afa2c (组件实现双击添加)
            
            // 创建组件信息并发送信号
            ComponentInfo component;
            component.name = componentName;
            component.type = componentType;
            component.level = componentLevel;
<<<<<<< HEAD
<<<<<<< HEAD
            component.iconPath = iconPath;
=======
>>>>>>> 9bd960c (V0.1)
=======
            component.iconPath = iconPath;
>>>>>>> d0afa2c (组件实现双击添加)
            
            // 查找完整的组件信息
            for (const ComponentInfo &info : m_componentTypes) {
                if (info.type == componentType) {
                    component.description = info.description;
                    break;
                }
            }
            
            emit componentAdded(component);
        }
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
void ComponentManager::showConfigureComponentDialog(QStandardItem *item)
{
    if (!item) {
        return;
    }
    
    // 根据组件类型显示不同的配置对话框
    QString componentType = item->data(Qt::UserRole).toString();
    
    if (componentType == "DIModule") {
        showDIModuleConfigDialog(item);
    } else if (componentType == "DOModule") {
        showDOModuleConfigDialog(item);
    } else {
        // 其他类型的组件配置
        QMessageBox::information(nullptr, "配置组件", "组件配置功能将在后续版本中实现");
    }
}

void ComponentManager::showDIModuleConfigDialog(QStandardItem *item)
{
    if (!item) {
        return;
    }
    
    // 创建DI模块配置对话框
    DIModuleConfigDialog dialog(m_diModule);
    
    if (dialog.exec() == QDialog::Accepted) {
        // 配置已保存，可以在这里更新项目树中的组件信息
        // 例如，更新组件名称或图标等
    }
}

void ComponentManager::showDOModuleConfigDialog(QStandardItem *item)
{
    QDialog dialog;
    dialog.setWindowTitle(tr("配置组件"));
    
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    
    // 组件名称
    QHBoxLayout *nameLayout = new QHBoxLayout();
    QLabel *nameLabel = new QLabel(tr("名称:"), &dialog);
    QLineEdit *nameEdit = new QLineEdit(&dialog);
    nameEdit->setText(item ? item->text() : "");
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);
    layout->addLayout(nameLayout);
    
    // 通信方式选择
    QHBoxLayout *commLayout = new QHBoxLayout();
    QLabel *commLabel = new QLabel(tr("通信方式:"), &dialog);
    QComboBox *commComboBox = new QComboBox(&dialog);
    
    // 添加通信方式选项
    commComboBox->addItem("TCP", TCP);
    commComboBox->addItem("UDP", UDP);
    commComboBox->addItem("CAN", CAN);
    commComboBox->addItem("MODBUS 485", MODBUS_485);
    commComboBox->addItem("ETHERCAT", ETHERCAT);
    
    // 如果是编辑现有组件，设置当前通信方式
    if (item) {
        QVariant commData = item->data(Qt::UserRole + 1); // 假设通信方式存储在UserRole+1
        if (commData.isValid()) {
            commComboBox->setCurrentIndex(commData.toInt());
        }
    }
    
    commLayout->addWidget(commLabel);
    commLayout->addWidget(commComboBox);
    layout->addLayout(commLayout);
    
    // 按钮
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    layout->addWidget(buttonBox);
    
    if (dialog.exec() == QDialog::Accepted) {
        QString name = nameEdit->text();
        if (!name.isEmpty()) {
            if (item) {
                // 更新组件名称
                item->setText(name);
                
                // 更新通信方式
                int commIndex = commComboBox->currentIndex();
                item->setData(commIndex, Qt::UserRole + 1);
                
                emit componentConfigured(item);
            }
        }
    }
}


// {
//     if (!item) {
//         return;
//     }
    
//     // 创建DO模块配置对话框
//     DOModuleConfigDialog dialog(m_doModule);
    
//     if (dialog.exec() == QDialog::Accepted) {
//         // 配置已保存，可以在这里更新项目树中的组件信息
//         // 例如，更新组件名称或图标等
//     }
// }

=======
void ComponentManager::showConfigureComponentDialog()
=======
void ComponentManager::showConfigureComponentDialog(QStandardItem *item)
>>>>>>> c7c6830 (增加DI模块配置界面)
{
    if (!item) {
        return;
    }
    
    // 根据组件类型显示不同的配置对话框
    QString componentType = item->data(Qt::UserRole).toString();
    
    if (componentType == "DIModule") {
        showDIModuleConfigDialog(item);
    } else {
        // 其他类型的组件配置
        QMessageBox::information(nullptr, "配置组件", "组件配置功能将在后续版本中实现");
    }
}

void ComponentManager::showDIModuleConfigDialog(QStandardItem *item)
{
    if (!item) {
        return;
    }
    
    // 创建DI模块配置对话框
    DIModuleConfigDialog dialog(m_diModule);
    
    if (dialog.exec() == QDialog::Accepted) {
        // 配置已保存，可以在这里更新项目树中的组件信息
        // 例如，更新组件名称或图标等
    }
}

>>>>>>> 9bd960c (V0.1)
void ComponentManager::showDeleteComponentDialog(QStandardItem *item)
{
    if (!item) {
        return;
    }
    
    QMessageBox msgBox;
    msgBox.setWindowTitle("删除组件");
    msgBox.setText(QString("确定要删除组件 \"%1\" 吗?").arg(item->text()));
    msgBox.setInformativeText("此操作不可撤销。");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    
    if (msgBox.exec() == QMessageBox::Yes) {
        emit componentDeleted(item);
    }
}

void ComponentManager::showMoveComponentDialog(QStandardItem *item)
{
    if (!item) {
        return;
    }
    
    QDialog dialog;
    dialog.setWindowTitle("移动组件");
    dialog.setMinimumWidth(400);
    
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    
    QLabel *label = new QLabel(QString("选择 \"%1\" 的新位置:").arg(item->text()));
    layout->addWidget(label);
    
    // 获取项目模型
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(item->model());
    if (!model) {
        return;
    }
    
    // 创建树形视图显示可能的目标位置
    QTreeView *treeView = new QTreeView(&dialog);
    treeView->setModel(model);
    treeView->expandAll();
    layout->addWidget(treeView);
    
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    layout->addWidget(buttonBox);
    
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    
    if (dialog.exec() == QDialog::Accepted) {
        QModelIndex selectedIndex = treeView->currentIndex();
        if (selectedIndex.isValid()) {
            QStandardItem *targetItem = model->itemFromIndex(selectedIndex);
            if (targetItem && targetItem != item) {
                emit componentMoved(item, targetItem);
            }
        }
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5b065cd (增加了上下移动组件的功能)
void ComponentManager::moveComponentUp(QStandardItem *item)
{
    if (!item) {
        return;
    }
    
    QStandardItem *parentItem = item->parent();
    if (!parentItem) {
        return;
    }
    
    int row = item->row();
    if (row <= 0) {
        // 已经是第一个，无法上移
        return;
    }
    
    // 从父项中移除该项
    QList<QStandardItem*> rowItems = parentItem->takeRow(row);
    
    // 在上一行位置插入
    parentItem->insertRow(row - 1, rowItems);
    
    // 发出顺序变更信号
    emit componentOrderChanged(rowItems.first(), true);
}

void ComponentManager::moveComponentDown(QStandardItem *item)
{
    if (!item) {
        return;
    }
    
    QStandardItem *parentItem = item->parent();
    if (!parentItem) {
        return;
    }
    
    int row = item->row();
    if (row >= parentItem->rowCount() - 1) {
        // 已经是最后一个，无法下移
        return;
    }
    
    // 从父项中移除该项
    QList<QStandardItem*> rowItems = parentItem->takeRow(row);
    
    // 在下一行位置插入
    parentItem->insertRow(row + 1, rowItems);
    
    // 发出顺序变更信号
    emit componentOrderChanged(rowItems.first(), false);
}

QList<ComponentInfo> ComponentManager::getComponentTypes() const
{
    return m_componentTypes;
}
<<<<<<< HEAD
=======
QList<ComponentInfo> ComponentManager::getComponentTypes() const
{
    return m_componentTypes;
}
>>>>>>> 9bd960c (V0.1)
=======
>>>>>>> c7c6830 (增加DI模块配置界面)
