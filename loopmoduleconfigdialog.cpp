#include "loopmoduleconfigdialog.h"
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

LoopModuleConfigDialog::LoopModuleConfigDialog(LoopModule *module,
                                               QWidget *parent)
    : QDialog(parent), m_module(module), m_currentLoopIndex(0) {
  setWindowTitle("回路模块配置");
  setMinimumSize(700, 500);

  setupUI();

  // Initialize selection
  if (m_module->getLoopCount() > 0) {
    updateDeviceTable(0);
  }
}

LoopModuleConfigDialog::~LoopModuleConfigDialog() {}

void LoopModuleConfigDialog::setupUI() {
  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  // Loop Count Configuration
  QHBoxLayout *loopCountLayout = new QHBoxLayout();
  QLabel *loopCountLabel = new QLabel("回路数量:", this);
  m_loopCountCombo = new QComboBox(this);
  m_loopCountCombo->addItem("2回路", 2);
  m_loopCountCombo->addItem("4回路", 4);
  m_loopCountCombo->addItem("8回路", 8);

  // Set current loop count
  int currentCount = m_module->getLoopCount();
  int index = m_loopCountCombo->findData(currentCount);
  if (index != -1) {
    m_loopCountCombo->setCurrentIndex(index);
  } else {
    // If custom count, maybe add it or just select nearest?
    // For now assume 2, 4, 8 are the options.
    m_loopCountCombo->setCurrentIndex(0);
  }

  loopCountLayout->addWidget(loopCountLabel);
  loopCountLayout->addWidget(m_loopCountCombo);

  // Loop Selection
  QLabel *loopSelectLabel = new QLabel("选择回路:", this);
  m_loopSelectCombo = new QComboBox(this);

  for (int i = 1; i <= m_module->getLoopCount(); ++i) {
    m_loopSelectCombo->addItem(QString("回路 %1").arg(i), i);
  }

  loopCountLayout->addSpacing(20);
  loopCountLayout->addWidget(loopSelectLabel);
  loopCountLayout->addWidget(m_loopSelectCombo);
  loopCountLayout->addStretch();

  mainLayout->addLayout(loopCountLayout);

  // Device Table
  m_deviceTable = new QTableWidget(0, 6, this); // 增加列数到6
  QStringList headers;
  headers << "地址"
          << "设备类型"
          << "描述"
          << "个性代码"
          << "盘号"
          << "卡号";
  m_deviceTable->setHorizontalHeaderLabels(headers);
  m_deviceTable->verticalHeader()->setVisible(false);
  m_deviceTable->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Interactive);
  m_deviceTable->horizontalHeader()->setStretchLastSection(true);
  m_deviceTable->setSelectionBehavior(QAbstractItemView::SelectRows);
  m_deviceTable->setSelectionMode(QAbstractItemView::SingleSelection);

  m_deviceTable->setColumnWidth(0, 60);  // 地址
  m_deviceTable->setColumnWidth(1, 150); // 设备类型
  m_deviceTable->setColumnWidth(2, 150); // 描述
  m_deviceTable->setColumnWidth(3, 100); // 个性代码
  m_deviceTable->setColumnWidth(4, 60);  // 盘号
  m_deviceTable->setColumnWidth(5, 60);  // 卡号

  mainLayout->addWidget(m_deviceTable);

  // Device Operations Buttons
  QHBoxLayout *deviceOpsLayout = new QHBoxLayout();
  m_addDetectorButton = new QPushButton("添加烟温复合探测器", this);
  m_addManualPointButton = new QPushButton("添加手动报警按钮", this);
  m_addInputOutputModuleButton =
      new QPushButton("添加输入输出模块", this); // 新增按钮
  m_removeDeviceButton = new QPushButton("删除设备", this);

  deviceOpsLayout->addWidget(m_addDetectorButton);
  deviceOpsLayout->addWidget(m_addManualPointButton);
  deviceOpsLayout->addWidget(m_addInputOutputModuleButton);
  deviceOpsLayout->addWidget(m_removeDeviceButton);
  deviceOpsLayout->addStretch();

  mainLayout->addLayout(deviceOpsLayout);

  // Dialog Buttons
  QHBoxLayout *buttonLayout = new QHBoxLayout();
  m_saveButton = new QPushButton("保存", this);
  m_cancelButton = new QPushButton("取消", this);

  buttonLayout->addStretch();
  buttonLayout->addWidget(m_saveButton);
  buttonLayout->addWidget(m_cancelButton);

  mainLayout->addLayout(buttonLayout);

  // Connections
  connect(m_loopCountCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &LoopModuleConfigDialog::onLoopCountChanged);
  connect(m_loopSelectCombo,
          QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &LoopModuleConfigDialog::onLoopSelectionChanged);

  connect(m_addDetectorButton, &QPushButton::clicked, this,
          &LoopModuleConfigDialog::onAddDetector);
  connect(m_addManualPointButton, &QPushButton::clicked, this,
          &LoopModuleConfigDialog::onAddManualPoint);
  connect(m_addInputOutputModuleButton, &QPushButton::clicked, this,
          &LoopModuleConfigDialog::onAddInputOutputModule); // 连接新槽函数
  connect(m_removeDeviceButton, &QPushButton::clicked, this,
          &LoopModuleConfigDialog::onRemoveDevice);

  connect(m_deviceTable, &QTableWidget::cellChanged, this,
          &LoopModuleConfigDialog::onDeviceChanged);

  connect(m_saveButton, &QPushButton::clicked, this,
          &LoopModuleConfigDialog::saveConfiguration);
  connect(m_cancelButton, &QPushButton::clicked, this,
          &LoopModuleConfigDialog::reject);
}

void LoopModuleConfigDialog::updateDeviceTable(int loopIndex) {
  // loopIndex is 0-based index from combo box, which corresponds to
  // loopNumber = loopIndex + 1
  if (loopIndex < 0 || loopIndex >= m_module->getLoopCount())
    return;

  m_currentLoopIndex = loopIndex;
  Loop *loop = m_module->getLoop(loopIndex + 1);
  if (!loop)
    return;

  disconnect(m_deviceTable, &QTableWidget::cellChanged, this,
             &LoopModuleConfigDialog::onDeviceChanged);

  m_deviceTable->setRowCount(0);

  for (int i = 0; i < loop->devices.size(); ++i) {
    const LoopDevice &device = loop->devices[i];
    m_deviceTable->insertRow(i);

    // Address (Read-only)
    QTableWidgetItem *addrItem =
        new QTableWidgetItem(QString::number(device.address));
    addrItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    m_deviceTable->setItem(i, 0, addrItem);

    // Type (Read-only for now, could be combo)
    QTableWidgetItem *typeItem = new QTableWidgetItem(device.type);
    typeItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    m_deviceTable->setItem(i, 1, typeItem);

    // Description (Editable)
    QTableWidgetItem *descItem = new QTableWidgetItem(device.description);
    m_deviceTable->setItem(i, 2, descItem);

    // Personal Code (Editable)
    QTableWidgetItem *codeItem = new QTableWidgetItem(device.personalCode);
    m_deviceTable->setItem(i, 3, codeItem);

    // Board Number (Editable)
    QTableWidgetItem *boardItem =
        new QTableWidgetItem(QString::number(device.boardNumber));
    m_deviceTable->setItem(i, 4, boardItem);

    // Card Number (Editable)
    QTableWidgetItem *cardItem =
        new QTableWidgetItem(QString::number(device.cardNumber));
    m_deviceTable->setItem(i, 5, cardItem);
  }

  connect(m_deviceTable, &QTableWidget::cellChanged, this,
          &LoopModuleConfigDialog::onDeviceChanged);
}

int LoopModuleConfigDialog::getNextAvailableAddress(int loopIndex) {
  Loop *loop = m_module->getLoop(loopIndex + 1);
  if (!loop)
    return 1;

  int maxAddr = 0;
  QVector<int> usedAddresses;
  for (const auto &d : loop->devices) {
    usedAddresses.append(d.address);
    if (d.address > maxAddr)
      maxAddr = d.address;
  }

  // Simple strategy: max + 1, or fill gaps. Let's do max + 1 for now.
  // Assuming max address is 255.
  if (maxAddr < 255) {
    return maxAddr + 1;
  }

  // If max is reached, look for gaps
  for (int i = 1; i <= 255; ++i) {
    if (!usedAddresses.contains(i))
      return i;
  }

  return -1; // Full
}

void LoopModuleConfigDialog::onLoopCountChanged(int index) {
  int newCount = m_loopCountCombo->itemData(index).toInt();
  m_module->setLoopCount(newCount);

  // Update loop selector
  m_loopSelectCombo->clear();
  for (int i = 1; i <= newCount; ++i) {
    m_loopSelectCombo->addItem(QString("回路 %1").arg(i), i);
  }

  m_currentLoopIndex = 0;
  m_loopSelectCombo->setCurrentIndex(0);
  updateDeviceTable(0);
}

void LoopModuleConfigDialog::onLoopSelectionChanged(int index) {
  updateDeviceTable(index);
}

void LoopModuleConfigDialog::onAddDetector() {
  int addr = getNextAvailableAddress(m_currentLoopIndex);
  if (addr == -1) {
    QMessageBox::warning(this, "添加失败", "回路已满，无法添加更多设备。");
    return;
  }

  LoopDevice device("烟温复合探测器", addr, "新探测器");
  if (m_module->addDevice(m_currentLoopIndex + 1, device)) {
    updateDeviceTable(m_currentLoopIndex);
  }
}

void LoopModuleConfigDialog::onAddManualPoint() {
  int addr = getNextAvailableAddress(m_currentLoopIndex);
  if (addr == -1) {
    QMessageBox::warning(this, "添加失败", "回路已满，无法添加更多设备。");
    return;
  }

  LoopDevice device("手动报警按钮", addr, "新手动按钮");
  if (m_module->addDevice(m_currentLoopIndex + 1, device)) {
    updateDeviceTable(m_currentLoopIndex);
  }
}

void LoopModuleConfigDialog::onAddInputOutputModule() {
  int addr = getNextAvailableAddress(m_currentLoopIndex);
  if (addr == -1) {
    QMessageBox::warning(this, "添加失败", "回路已满，无法添加更多设备。");
    return;
  }

  LoopDevice device("输入输出模块", addr, "新模块");
  if (m_module->addDevice(m_currentLoopIndex + 1, device)) {
    updateDeviceTable(m_currentLoopIndex);
  }
}

void LoopModuleConfigDialog::onRemoveDevice() {
  int row = m_deviceTable->currentRow();
  if (row < 0)
    return;

  int addr = m_deviceTable->item(row, 0)->text().toInt();

  if (QMessageBox::question(
          this, "确认删除",
          QString("确定要删除地址为 %1 的设备吗？").arg(addr)) ==
      QMessageBox::Yes) {
    m_module->removeDevice(m_currentLoopIndex + 1, addr);
    updateDeviceTable(m_currentLoopIndex);
  }
}

void LoopModuleConfigDialog::onDeviceChanged(int row, int column) {
  int addr = m_deviceTable->item(row, 0)->text().toInt();
  QString newValue = m_deviceTable->item(row, column)->text();

  Loop *loop = m_module->getLoop(m_currentLoopIndex + 1);
  if (loop) {
    for (auto &d : loop->devices) {
      if (d.address == addr) {
        switch (column) {
        case 2: // Description
          d.description = newValue;
          break;
        case 3: // Personal Code
          d.personalCode = newValue;
          break;
        case 4: // Board Number
          d.boardNumber = newValue.toInt();
          break;
        case 5: // Card Number
          d.cardNumber = newValue.toInt();
          break;
        }
        break;
      }
    }
  }
}

void LoopModuleConfigDialog::saveConfiguration() {
  QMessageBox::information(this, "保存配置", "回路模块配置已保存");
  accept();
}
