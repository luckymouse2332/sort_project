#include <Arduino.h>
#include <Servo.h>

#include "main.h"
#include "conveyor.h"
#include "sensor.h"

/**
 * 初始化函数
 */
void setup()
{
  Conveyor::get_instance().setup();

  // 光电传感器
  pinMode(5, INPUT);

  Serial.begin(9600);

  while (Serial.available())
  {
    ;
  }
}

/**
 * 主函数
 */
void loop()
{
  auto conveyor = Conveyor::get_instance();
  if (is_sensor_blocked(5))
  {
    conveyor.stop();
  }
  else
  {
    conveyor.motor_forward();
  }
}