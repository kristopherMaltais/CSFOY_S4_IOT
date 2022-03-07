#include <Arduino.h>
#include <DEL.h>

// ** Constructeurs ** //
DEL::DEL(const int& p_pinDEL) : m_pinDEL(p_pinDEL)
{
    Serial.end();
    Serial.begin(9600);

    pinMode(this->m_pinDEL, OUTPUT);
}

// ** Méthodes ** //
void DEL::allume() const
{
    digitalWrite(this->m_pinDEL, HIGH);
};

void DEL::eteindre() const
{
    digitalWrite(this->m_pinDEL, LOW);
};