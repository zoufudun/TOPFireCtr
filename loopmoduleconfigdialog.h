#ifndef LOOPMODULECONFIGDIALOG_H
#define LOOPMODULECONFIGDIALOG_H

#include "loopmodule.h"
#include <QComboBox>
#include <QDialog>
#include <QPushButton>
#include <QTableWidget>


class LoopModuleConfigDialog : public QDialog {
  Q_OBJECT

public:
  explicit LoopModuleConfigDialog(LoopModule *module,
                                  QWidget *parent = nullptr);
  ~LoopModuleConfigDialog();

private slots:
  void onLoopCountChanged(int index);
  void onLoopSelectionChanged(int index);
  void onAddDetector();
  void onAddManualPoint();
  void onAddInputOutputModule(); // 新增槽函数
  void onRemoveDevice();
  void onDeviceChanged(int row, int column);
  void saveConfiguration();

private:
  void setupUI();
  void updateDeviceTable(int loopIndex);
  int getNextAvailableAddress(int loopIndex);

  LoopModule *m_module;
  int m_currentLoopIndex;

  QComboBox *m_loopCountCombo;
  QComboBox *m_loopSelectCombo;
  QTableWidget *m_deviceTable;
  QPushButton *m_addDetectorButton;
  QPushButton *m_addManualPointButton;
  QPushButton *m_addInputOutputModuleButton; // 新增按钮
  QPushButton *m_removeDeviceButton;
  QPushButton *m_saveButton;
  QPushButton *m_cancelButton;
};

#endif // LOOPMODULECONFIGDIALOG_H
