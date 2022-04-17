#include <Lumiere.h>
#include <Arduino.h>

Lumiere::Lumiere(uint8_t p_pin) : m_pin(p_pin)
{
    pinMode(p_pin, OUTPUT);
}

void Lumiere::allumer()
{
    digitalWrite(this->m_pin, HIGH);
}

void Lumiere::eteindre()
{
    digitalWrite(this->m_pin, LOW);
}
