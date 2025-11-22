#include "loopmodule.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

LoopModule::LoopModule(QObject *parent)
    : QObject(parent), m_loopCount(2) // 默认2个回路
{
  m_loops.resize(m_loopCount);
  for (int i = 0; i < m_loopCount; ++i) {
    m_loops[i].loopNumber = i + 1; // 回路编号从1开始
  }
}

LoopModule::~LoopModule() {}

void LoopModule::setLoopCount(int count) {
  if (count < 1)
    return;

  m_loopCount = count;
  m_loops.resize(m_loopCount);

  for (int i = 0; i < m_loopCount; ++i) {
    m_loops[i].loopNumber = i + 1;
  }
}

int LoopModule::getLoopCount() const { return m_loopCount; }

Loop *LoopModule::getLoop(int loopNumber) {
  // loopNumber is 1-based index
  if (loopNumber >= 1 && loopNumber <= m_loopCount) {
    return &m_loops[loopNumber - 1];
  }
  return nullptr;
}

bool LoopModule::addDevice(int loopNumber, const LoopDevice &device) {
  Loop *loop = getLoop(loopNumber);
  if (!loop)
    return false;

  // Check if address already exists
  for (const auto &d : loop->devices) {
    if (d.address == device.address) {
      return false; // Address conflict
    }
  }

  loop->devices.append(device);
  return true;
}

bool LoopModule::removeDevice(int loopNumber, int address) {
  Loop *loop = getLoop(loopNumber);
  if (!loop)
    return false;

  for (int i = 0; i < loop->devices.size(); ++i) {
    if (loop->devices[i].address == address) {
      loop->devices.removeAt(i);
      return true;
    }
  }

  return false;
}

LoopDevice LoopModule::getDevice(int loopNumber, int address) const {
  if (loopNumber >= 1 && loopNumber <= m_loopCount) {
    const Loop &loop = m_loops[loopNumber - 1];
    for (const auto &d : loop.devices) {
      if (d.address == address) {
        return d;
      }
    }
  }
  return LoopDevice();
}

void LoopModule::saveConfiguration(const QString &filePath) {
  QJsonObject rootObj;

  rootObj["loopCount"] = m_loopCount;

  QJsonArray loopsArray;
  for (int i = 0; i < m_loopCount; ++i) {
    QJsonObject loopObj;
    loopObj["loopNumber"] = m_loops[i].loopNumber;

    QJsonArray devicesArray;
    for (const auto &device : m_loops[i].devices) {
      QJsonObject deviceObj;
      deviceObj["type"] = device.type;
      deviceObj["address"] = device.address;
      deviceObj["description"] = device.description;
      deviceObj["personalCode"] = device.personalCode;
      deviceObj["boardNumber"] = device.boardNumber;
      deviceObj["cardNumber"] = device.cardNumber;
      devicesArray.append(deviceObj);
    }

    loopObj["devices"] = devicesArray;
    loopsArray.append(loopObj);
  }

  rootObj["loops"] = loopsArray;

  QJsonDocument doc(rootObj);
  QFile file(filePath);
  if (file.open(QIODevice::WriteOnly)) {
    file.write(doc.toJson());
    file.close();
  }
}

void LoopModule::loadConfiguration(const QString &filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly)) {
    return;
  }

  QByteArray data = file.readAll();
  file.close();

  QJsonDocument doc = QJsonDocument::fromJson(data);
  if (doc.isNull() || !doc.isObject()) {
    return;
  }

  QJsonObject rootObj = doc.object();

  if (rootObj.contains("loopCount")) {
    setLoopCount(rootObj["loopCount"].toInt());
  }

  if (rootObj.contains("loops") && rootObj["loops"].isArray()) {
    QJsonArray loopsArray = rootObj["loops"].toArray();

    for (int i = 0; i < loopsArray.size() && i < m_loopCount; ++i) {
      QJsonObject loopObj = loopsArray[i].toObject();
      int loopNumber = loopObj["loopNumber"].toInt();

      // Ensure we are populating the correct loop
      Loop *loop = getLoop(loopNumber);
      if (!loop)
        continue;

      loop->devices.clear();

      if (loopObj.contains("devices") && loopObj["devices"].isArray()) {
        QJsonArray devicesArray = loopObj["devices"].toArray();

        for (const auto &val : devicesArray) {
          QJsonObject deviceObj = val.toObject();
          LoopDevice device;
          device.type = deviceObj["type"].toString();
          device.address = deviceObj["address"].toInt();
          device.description = deviceObj["description"].toString();
          device.personalCode = deviceObj["personalCode"].toString();
          device.boardNumber = deviceObj["boardNumber"].toInt();
          device.cardNumber = deviceObj["cardNumber"].toInt();
          loop->devices.append(device);
        }
      }
    }
  }
}
