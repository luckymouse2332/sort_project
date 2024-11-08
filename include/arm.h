#ifndef ARM_H
#define ARM_H

#include "MeArm.h"

/**
 * 机械臂控制类
 */
class Arm : public MeArm {
public:
  /**
   * 初始化机械臂
   */
  void setup(int pinBase, int pinShoulder, int pinElbow, int pinClaw);

  /**
   * 抓取物块
   */
  void run_catch(int x, int y, int z);


  /**
   * 放置物块
   */
  void run_place(int x, int y, int z);
private:
  int m_x0 = 0;
  int m_y0 = 100;
  int m_z0 = 60;

  int pinBase = 11;
  int pinShoulder = 10;
  int pinElbow = 9;
  int pinClaw = 6;
};

#endif