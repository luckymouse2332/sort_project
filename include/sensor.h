#ifndef SENSOR_H
#define SENSOR_H

/**
 * 机械臂处的光电传感器
 */
#define ARM_SENSOR_PIN 5

/**
 * 传送带结束处的光电传感器
 */
#define END_SENSOR_PIN 6

/**
 * 查看光电传感器前方是否有物品
 */
bool is_sensor_blocked(int pin);

#endif