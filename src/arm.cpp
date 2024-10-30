#include "arm.h"

Arm &Arm::get_instance()
{
  static Arm arm;
  if (!arm.initialized)
  { // 没有初始化
    // 执行初始化操作
    arm.m_arm.begin(arm.pinBase, arm.pinShoulder, arm.pinElbow, arm.pinClaw);
  }
  return arm;
}

void Arm::run_catch(int x, int y)
{
  if (!m_arm.isReachable(x, y, m_z0)) {
    String logError = "Error: Can't reach the position of:";
    logError.concat("x: " + x);
    logError.concat("y: " + y);
    logError.concat("z: " + m_z0);

    Serial.println(logError);
    return;
  }
  m_arm.openClaw();
  m_arm.snapToXYZ(x, y, m_z0);
  m_arm.closeClaw();
}

void Arm::run_place(int x, int y)
{
  if (!m_arm.isReachable(x, y, m_z0)) {
    String logError = "Error: Can't reach the position of:";
    logError.concat("x: " + x);
    logError.concat("y: " + y);
    logError.concat("z: " + m_z0);
    
    Serial.println(logError);
    return;
  }
  m_arm.snapToXYZ(x, y, m_z0);
  m_arm.openClaw();
  m_arm.snapToXYZ(m_x0, m_y0, m_z0);
}
