#include "conveyor.h"
#include <Arduino.h>

void Conveyor::setup()
{
  // 引脚定义
  pinMode(motor_forward_pin, OUTPUT);
  pinMode(motor_reverse_pin, OUTPUT);
  pinMode(motor_pwm_pin, OUTPUT);
}

void Conveyor::motor_forward()
{
  // 电机正转启动
  digitalWrite(motor_forward_pin, HIGH);
  // 电机反转关闭
  digitalWrite(motor_reverse_pin, LOW);

  // pwm调速
  analogWrite(motor_pwm_pin, 250);
}

void Conveyor::motor_reverse()
{
  // 电机正转关闭
  digitalWrite(motor_forward_pin, LOW);
  // 电机反转启动
  digitalWrite(motor_reverse_pin, HIGH);

  // pwm调速
  analogWrite(motor_pwm_pin, 250);
}

void Conveyor::stop()
{
  // pwm调速
  analogWrite(motor_pwm_pin, LOW);
}
