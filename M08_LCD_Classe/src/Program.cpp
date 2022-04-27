#include <Program.h>
#include <LCD1602ProxyI2C.h>
#include <Arduino.h>

Program::Program()
{
    Serial.begin(9600);
    LCD1602ProxyI2C* lcd = new LCD1602ProxyI2C();
    this->m_LCD = new LCD1602(lcd);
    this->m_LCD->definirPositionCurseur(1, 16);

    String test = "test";
    this->m_LCD->afficher(test);
}

void Program::loop()
{
    
}