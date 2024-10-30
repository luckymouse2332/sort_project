#include <Arduino.h>
#include <Servo.h>

#include "main.h"
#include "conveyor.h"
#include "sensor.h"
#include "arm.h"
#include "utils/command_parser.h"

/**
 * 初始化函数
 */
void setup()
{
  Conveyor::get_instance().setup();

  // 光电传感器
  pinMode(ARM_SENSOR_PIN, INPUT);
  pinMode(END_SENSOR_PIN, INPUT);

  Serial.begin(115200);

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
  // 获取控制对象
  auto conveyor = Conveyor::get_instance();
  auto arm = Arm::get_instance();

  if (is_sensor_blocked(ARM_SENSOR_PIN))
  {
    conveyor.stop(); // 传送带停止运行

    // 默认的位置参数，防止解析失败
    int x = 30, y = 100, colorCode = 0;

    // 从串口接收指令
    auto command = Serial.readString();

    if (command) // 读取成功
    {
      // 解析指令
      parse_command(command, x, y, colorCode);
    }

    // 抓取物块
    arm.run_catch(x, y);
    // 放置物块
    arm.run_place(50, 50);
  }
  else
  {
    // 启动传送带
    conveyor.motor_forward();
  }
}