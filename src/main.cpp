#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "conveyor.h"
#include "arm.h"

Arm placeArm, sortArm;

LiquidCrystal_I2C lcd(0x27, 20, 4);

Conveyor conveyor(12, 13, 3);

// 颜色位置，颜色判断
const int X[10] = {0, -120, 0}, Y[10] = {0, 0, 120};
int colorCode = 1;

/**
 * 初始化函数
 */
void setup()
{
  Serial.begin(115200);

  lcd.init();
  conveyor.setup();
  sortArm.begin(7, 6, 5, 4);
  // placeArm.begin(11, 10, 9, 8);
  lcd.backlight();

  conveyor.motor_forward();
}

/**
 * 主函数
 */
void loop()
{
  while (digitalRead(A1) == 1) //等待物块到传送带
  {
    delay(5);
  }
  if (digitalRead(A1) == 0) // 置物台有物块
  {
    conveyor.stop();
    // 运来了新的物块，启动传送带
    // placeArm.run_catch(140, 0, 60);
    // placeArm.run_place(0, 120, 80);
    conveyor.motor_forward();
  }
  while (Serial.available())
  {
    String data = Serial.readString();
    if (data[0] == 'B')
    {
      // 蓝色
      colorCode = 2;
      lcd.println("Blue block");
      break;
    }
    else if (data[0] == 'R')
    {
      // 红色
      colorCode = 1;
      lcd.println("Red block");
      break;
    }
  }

  while (digitalRead(A0) == 1) //等待物块到传送带
  {
    delay(5);
  }
  conveyor.stop();
  sortArm.run_catch(120, 0, 60);
  sortArm.run_place(X[colorCode], Y[colorCode], 80);
}
