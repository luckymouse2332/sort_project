#include "utils/command_parser.h"

void parse_command(String s, int &x, int &y, int &color)
{
  int state = 0;
  x = 0;
  y = 0;
  color = 0;
  for (unsigned int i = 0; i < s.length(); i++)
  {
    if (s[i] >= '0' && s[i] <= '9')
    {
      if (state == 0)
        x = x * 10 + (s[i] - '0');
      if (state == 1)
        y = y * 10 + (s[i] - '0');
      if (state == 2)
        color = color * 10 + (s[i] - '0');
    }
    else
      state++;
  }
}