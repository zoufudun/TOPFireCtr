#ifndef DIMODULECONFIGDIALOG_H
#define DIMODULECONFIGDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QTabWidget>
#include <QTableWidget>
#include <QPushButton>
#include "dimodule.h"

class DIModuleConfigDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DIModuleConfigDialog(DIModule *module, QWidget *parent = nullptr);
    ~DIModuleConfigDialog();
    
private slots:
    void onChannelCountChanged(int index);
    void onBitVariableChanged(int row, int column);
    void saveConfiguration();
    void onChannelSelectionChanged(int index);
    
private:
    void setupUI();
    void updateChannelTabs();
    void updateBitTable(int channelIndex);
    
    DIModule *m_module;
    QComboBox *m_channelCountCombo;
<<<<<<< HEAD
<<<<<<< HEAD
    QComboBox *m_channelSelectCombo;  // 通道选择下拉框
    QTableWidget *m_bitTable;         // 使用单个表格替代多个选项卡
    QPushButton *m_saveButton;
    QPushButton *m_cancelButton;
    int m_currentChannelIndex;        // 当前选中的通道索引
=======
    QComboBox *m_channelSelectCombo;
    //QTabWidget *m_channelTabs;
    QTableWidget *m_bitTable;
    //QVector<QTableWidget*> m_bitTables;
    
    QPushButton *m_saveButton;
    QPushButton *m_cancelButton;
    int m_currentChannelIndex; // 通道数量
>>>>>>> c7c6830 (增加DI模块配置界面)
=======
    QComboBox *m_channelSelectCombo;  // 通道选择下拉框
    QTableWidget *m_bitTable;         // 使用单个表格替代多个选项卡
    QPushButton *m_saveButton;
    QPushButton *m_cancelButton;
    int m_currentChannelIndex;        // 当前选中的通道索引
>>>>>>> a2577e0 (DI模块配置界面增加值列)
};

#endif // DIMODULECONFIGDIALOG_H
