#ifndef CONVEYOR_H
#define CONVEYOR_H

/**
 * 传送带类
 */
class Conveyor {
public:
  /**
   * 构造函数
   * @param forward_pin 正转控制引脚
   * @param reverse_pin 反转控制引脚
   * @param pwm_pin pwm调速引脚
   */
  Conveyor(int forward_pin, int reverse_pin, int pwm_pin) 
    : motor_forward_pin(forward_pin), motor_reverse_pin(reverse_pin), motor_pwm_pin(pwm_pin) {}

  /**
   * 获取实例
   */
  static Conveyor& get_instance() {
    static Conveyor instance(3,2,4);
    return instance;
  }

  /**
   * 初始化函数
   */
  void setup();
public:
  /**
   * 正转
   */
  void motor_forward();

  /**
   * 反转
   */
  void motor_reverse();

  /**
   * 停止
   */
  void stop();

private:
  int motor_forward_pin;
  int motor_reverse_pin;
  int motor_pwm_pin;
};


#endif