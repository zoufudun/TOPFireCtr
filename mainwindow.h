#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QDockWidget>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include "projectmanager.h"
#include "componentmanager.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "thememanager.h"
=======
>>>>>>> 9bd960c (V0.1)
=======
#include "thememanager.h"
>>>>>>> 5b065cd (增加了上下移动组件的功能)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
<<<<<<< HEAD
    explicit MainWindow(QWidget *parent = nullptr);
=======
    MainWindow(QWidget *parent = nullptr);
>>>>>>> 9bd960c (V0.1)
=======
    explicit MainWindow(QWidget *parent = nullptr);
>>>>>>> 5b065cd (增加了上下移动组件的功能)
    ~MainWindow();

private slots:
    void newProject();
    void openProject();
    void saveProject();
    void saveProjectAs();
    void renameProject();           // 添加重命名项目的槽函数
    void addComponent();
    void deleteComponent();         // 添加删除组件的槽函数
    void moveComponent();           // 添加移动组件的槽函数
    void configureComponent();
    void onComponentAdded(const ComponentInfo &component);
<<<<<<< HEAD
<<<<<<< HEAD
    void onComponentDeleted(QStandardItem *item);
    void onComponentMoved(QStandardItem *item, QStandardItem *newParent);
    void onComponentConfigured(QStandardItem *item);
    void moveComponentUp();
    void moveComponentDown();
    void onComponentOrderChanged(QStandardItem *parent, int oldIndex, int newIndex);

private:
    void showProjectContextMenu(const QPoint &pos);
    void updatePropertiesView(QStandardItem *item);  // Add this declaration
    void changeTheme();
    void setDefaultTheme();
    void setAtomOneTheme();
    void setSolarizedLightTheme();
=======
    void onComponentDeleted(QStandardItem *item);        // 添加组件删除的处理函数
    void onComponentMoved(QStandardItem *item, QStandardItem *newParent); // 添加组件移动的处理函数
=======
    void onComponentDeleted(QStandardItem *item);
    void onComponentMoved(QStandardItem *item, QStandardItem *newParent);
<<<<<<< HEAD
    void showProjectContextMenu(const QPoint &pos);
>>>>>>> b22ee86 (组件列表中添加组件删除等功能)

private:
>>>>>>> 9bd960c (V0.1)
=======

    void moveComponentUp();
    void moveComponentDown();
    void onComponentOrderChanged(QStandardItem *item, bool moveUp);

private:
    void showProjectContextMenu(const QPoint &pos);
    void changeTheme();
    void setDefaultTheme();
    void setAtomOneTheme();
    void setSolarizedLightTheme();
>>>>>>> 5b065cd (增加了上下移动组件的功能)
    void setupUI();
    void createActions();
    void createMenus();
    void createToolbars();
    void createDockWindows();

    QTreeView *projectTreeView;
    QDockWidget *projectDock;
    QDockWidget *componentDock;
    QDockWidget *propertiesDock;

    ProjectManager *projectManager;
    ComponentManager *componentManager;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5b065cd (增加了上下移动组件的功能)
    ThemeManager *themeManager;
    QMenu *themeMenu;
    QMenu *editMenu;  // Add this line to declare editMenu
    QAction *defaultThemeAction;
    QAction *atomOneThemeAction;
    QAction *solarizedLightThemeAction;
<<<<<<< HEAD
=======
>>>>>>> 9bd960c (V0.1)
=======
>>>>>>> 5b065cd (增加了上下移动组件的功能)

    // Actions
    QAction *newProjectAction;
    QAction *openProjectAction;
    QAction *saveProjectAction;
    QAction *saveAsProjectAction;
    QAction *renameProjectAction;   // 添加重命名项目的动作
    QAction *addComponentAction;
    QAction *deleteComponentAction; // 添加删除组件的动作
    QAction *moveComponentAction;   // 添加移动组件的动作
    QAction *configureComponentAction;
    QAction *exitAction;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5b065cd (增加了上下移动组件的功能)
    QAction *moveUpAction;
    QAction *moveDownAction;
};

#endif // MAINWINDOW_H
<<<<<<< HEAD
=======
};

#endif // MAINWINDOW_H
>>>>>>> 9bd960c (V0.1)
=======
>>>>>>> 5b065cd (增加了上下移动组件的功能)
