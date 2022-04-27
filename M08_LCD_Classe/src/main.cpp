#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Program.h>
#include <Wire.h>

Program* programme;
//LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //Serial.begin(9600);
  programme = new Program();
}

void loop() {
  //programme->loop();
}