#ifndef LOOPMODULE_H
#define LOOPMODULE_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QVector>


// 定义回路设备结构
struct LoopDevice {
  QString
      type; // 设备类型 (e.g., "烟温复合探测器", "手动报警按钮", "输入输出模块")
  int address;          // 设备地址
  QString description;  // 设备描述
  QString personalCode; // 设备的个性代码
  int boardNumber;      // 设备的盘号
  int cardNumber;       // 设备的卡号

  LoopDevice() : address(0), boardNumber(0), cardNumber(0) {}
  LoopDevice(const QString &t, int a, const QString &d = "",
             const QString &code = "", int board = 0, int card = 0)
      : type(t), address(a), description(d), personalCode(code),
        boardNumber(board), cardNumber(card) {}
};

// 定义回路结构
struct Loop {
  int loopNumber;              // 回路编号
  QVector<LoopDevice> devices; // 回路上的设备列表

  Loop() : loopNumber(0) {}
};

// 回路模块类
class LoopModule : public QObject {
  Q_OBJECT

public:
  explicit LoopModule(QObject *parent = nullptr);
  ~LoopModule();

  // 设置回路数量
  void setLoopCount(int count);
  int getLoopCount() const;

  // 获取指定回路
  Loop *getLoop(int loopNumber);

  // 添加设备
  bool addDevice(int loopNumber, const LoopDevice &device);

  // 移除设备
  bool removeDevice(int loopNumber, int address);

  // 获取设备
  LoopDevice getDevice(int loopNumber, int address) const;

  // 保存和加载配置
  void saveConfiguration(const QString &filePath);
  void loadConfiguration(const QString &filePath);

private:
  int m_loopCount;       // 回路数量
  QVector<Loop> m_loops; // 回路列表
};

#endif // LOOPMODULE_H
