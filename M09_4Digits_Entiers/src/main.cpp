#include <Arduino.h>
#include <TM1637Display.h>
#include <Program.h>

Program* programme;

void setup()
{
  programme = new Program();
}

void loop()
{
  programme->loop();
}