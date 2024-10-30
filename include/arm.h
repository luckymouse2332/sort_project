#ifndef ARM_H
#define ARM_H

#include "MeArm.h"

/**
 * 机械臂控制类
 */
class Arm {
public:
  
  /**
   * 因为是全局单例，使用了简单的单例模式
   */
  static Arm& get_instance();
public:
  /**
   * 抓取物块
   */
  void run_catch(int x, int y);


  /**
   * 放置物块
   */
  void run_place(int x, int y);
private:
  int m_x0 = 50;
  int m_y0 = 0;
  int m_z0 = 100;

  int pinBase = 11;
  int pinShoulder = 10;
  int pinElbow = 9;
  int pinClaw = 6;

  MeArm m_arm;

  /**
   * 是否已经初始化过
   */
  bool initialized = false;
};

#endif