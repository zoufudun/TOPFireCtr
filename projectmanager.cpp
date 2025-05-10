#include "projectmanager.h"
#include <QtXml/QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

ProjectManager::ProjectManager(QObject *parent)
    : QObject(parent), m_hasUnsavedChanges(false)
{
    m_model = new QStandardItemModel(this);
    m_model->setHorizontalHeaderLabels(QStringList() << "项目结构");
}

ProjectManager::~ProjectManager()
{
}

bool ProjectManager::hasUnsavedChanges() const
{
    return m_hasUnsavedChanges;
}

void ProjectManager::newProject()
{
    m_currentProjectPath.clear();
    m_hasUnsavedChanges = false;
    // Add initialization code for a new project
}

// 在保存项目时
void ProjectManager::saveProject(const QString &filePath)
{
    m_currentProjectPath = filePath;  // 修复：使用 filePath 而不是 path
    m_hasUnsavedChanges = false;
    
    // 创建 XML 文档
    QDomDocument doc("ControllerProject");
    QDomElement rootElement = doc.createElement("Project");
    doc.appendChild(rootElement);
    
    // 保存组件信息
    QDomElement componentsElement = doc.createElement("Components");
    rootElement.appendChild(componentsElement);
    
    QStandardItem *rootItem = projectModel()->item(0);
    if (rootItem) {
        for (int i = 0; i < rootItem->rowCount(); ++i) {
            QStandardItem *moduleItem = rootItem->child(i);
            QDomElement moduleElement = doc.createElement("Module");
            moduleElement.setAttribute("name", moduleItem->text());
            moduleElement.setAttribute("type", moduleItem->data(Qt::UserRole).toString());
            
            // 保存通信方式（如果是DI模块）
            if (moduleItem->data(Qt::UserRole).toString() == "DIModule") {
                int commType = moduleItem->data(Qt::UserRole + 1).toInt();
                moduleElement.setAttribute("communicationType", commType);
            }
            
            componentsElement.appendChild(moduleElement);
            
            // 保存子组件
            for (int j = 0; j < moduleItem->rowCount(); ++j) {
                QStandardItem *subItem = moduleItem->child(j);
                QDomElement subElement = doc.createElement("SubModule");
                subElement.setAttribute("name", subItem->text());
                subElement.setAttribute("type", subItem->data(Qt::UserRole).toString());
                moduleElement.appendChild(subElement);
            }
        }
    }
    
    // 将文档保存到文件
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << doc.toString();
        file.close();
    }
}

// 在加载项目时 - 删除重复的方法声明，合并功能
void ProjectManager::loadProject(const QString &filePath)
{
    m_currentProjectPath = filePath;  // 修复：使用 filePath 而不是 path
    m_hasUnsavedChanges = false;
    
    // 清除现有模型
    m_model->clear();
    m_model->setHorizontalHeaderLabels(QStringList() << "项目结构");
    
    // 从文件加载 XML
    QDomDocument doc;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (doc.setContent(&file)) {
            QDomElement rootElement = doc.documentElement();
            
            // 创建项目根节点
            QStandardItem *rootItem = new QStandardItem(QFileInfo(filePath).baseName());
            m_model->appendRow(rootItem);
            
            // 加载组件信息
            QDomElement componentsElement = rootElement.firstChildElement("Components");
            if (!componentsElement.isNull()) {
                QDomElement moduleElement = componentsElement.firstChildElement("Module");
                while (!moduleElement.isNull()) {
                    QString name = moduleElement.attribute("name");
                    QString type = moduleElement.attribute("type");
                    
                    QStandardItem *moduleItem = new QStandardItem(name);
                    moduleItem->setData(type, Qt::UserRole);
                    
                    // 加载通信方式（如果是DI模块）
                    if (type == "DIModule" && moduleElement.hasAttribute("communicationType")) {
                        int commType = moduleElement.attribute("communicationType").toInt();
                        moduleItem->setData(commType, Qt::UserRole + 1);
                    }
                    
                    // 设置图标
                    if (type == "HostModule") {
                        moduleItem->setIcon(QIcon(":/icons/host.png"));
                    } else if (type == "DIModule") {
                        moduleItem->setIcon(QIcon(":/icons/di.png"));
                    } else if (type == "DOModule") {
                        moduleItem->setIcon(QIcon(":/icons/do.png"));
                    } else if (type == "AIModule") {
                        moduleItem->setIcon(QIcon(":/icons/ai.png"));
                    } else if (type == "AOModule") {
                        moduleItem->setIcon(QIcon(":/icons/ao.png"));
                    }
                    
                    rootItem->appendRow(moduleItem);
                    
                    // 加载子组件
                    QDomElement subElement = moduleElement.firstChildElement("SubModule");
                    while (!subElement.isNull()) {
                        QString subName = subElement.attribute("name");
                        QString subType = subElement.attribute("type");
                        
                        QStandardItem *subItem = new QStandardItem(subName);
                        subItem->setData(subType, Qt::UserRole);
                        moduleItem->appendRow(subItem);
                        
                        subElement = subElement.nextSiblingElement("SubModule");
                    }
                    
                    moduleElement = moduleElement.nextSiblingElement("Module");
                }
            }
        }
        file.close();
    }
}

void ProjectManager::setUnsavedChanges(bool unsaved)
{
    m_hasUnsavedChanges = unsaved;
}

QString ProjectManager::currentProjectPath() const
{
    return m_currentProjectPath;
}

QStandardItemModel* ProjectManager::projectModel()
{
    return m_model;
}

void ProjectManager::renameProject(const QString &newName)
{
    if (m_model->rowCount() > 0) {
        QStandardItem *rootItem = m_model->item(0);
        rootItem->setText(newName);
        m_hasUnsavedChanges = true;
    }
}
