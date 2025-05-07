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
#include "thememanager.h"
=======
>>>>>>> 9bd960c (V0.1)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit MainWindow(QWidget *parent = nullptr);
=======
    MainWindow(QWidget *parent = nullptr);
>>>>>>> 9bd960c (V0.1)
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

private:
>>>>>>> 9bd960c (V0.1)
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
    ThemeManager *themeManager;
    QMenu *themeMenu;
    QMenu *editMenu;  // Add this line to declare editMenu
    QAction *defaultThemeAction;
    QAction *atomOneThemeAction;
    QAction *solarizedLightThemeAction;
=======
>>>>>>> 9bd960c (V0.1)

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
    QAction *moveUpAction;
    QAction *moveDownAction;
};

#endif // MAINWINDOW_H
=======
};

#endif // MAINWINDOW_H
>>>>>>> 9bd960c (V0.1)
