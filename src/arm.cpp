#include "arm.h"

void Arm::setup(int pinBase, int pinShoulder, int pinElbow, int pinClaw)
{
  begin(pinBase, pinShoulder, pinElbow, pinClaw);
  snapToXYZ(m_x0, m_y0, m_z0);
  openClaw();
}

void Arm::run_catch(int x, int y, int z)
{
  snapToXYZ(x / 2, y / 2, z + 20);
  delay(1000);
  openClaw();
  delay(1000);
  snapToXYZ(x, y, z);
  delay(1000);
  closeClaw();
  delay(1000);
  snapToXYZ(x / 2, y / 2, z + 20);
  delay(1000);
}

void Arm::run_place(int x, int y, int z)
{
  snapToXYZ(x / 2, y / 2, z + 40);
  delay(1000);
  snapToXYZ(x, y, z);
  delay(1000);
  openClaw();
  delay(1000);
  snapToXYZ(x / 2, y / 2, z);
  delay(1000);
}
