#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <Arduino.h>

/**
 * 处理输入的数据，进行转换，然后赋值到x y上
 * @param s 输入的指令，格式为 {x}#{y}#{color}，其中"{}"内的数据类型为int，color为约定好的颜色
 * @param x 输出的x
 * @param y 输出的y
 * @param color 输出的color
 */
void parse_command(String s, int &x, int &y, int &color);

#endif