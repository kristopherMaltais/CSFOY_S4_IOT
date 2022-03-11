// Fait avec Gabriel Tremblay
#include "MorseDEL.h"
#include <Arduino.h>

MorseDEL::MorseDEL(int p_dureePoint, int p_pinDEL) : Morse(p_dureePoint) 
{ 
    this->m_pinDEL = p_pinDEL; 
};
void MorseDEL::afficherPoint() 
{
    digitalWrite(this->m_pinDEL, HIGH);
    delay(this->getDureePoint());
    digitalWrite(this->m_pinDEL, LOW);
    delay(this->getDureePoint());
};
void MorseDEL::afficherTrait() 
{
    digitalWrite(this->m_pinDEL, HIGH);
    delay(this->getDureePoint() * 3);
    digitalWrite(this->m_pinDEL, LOW);
    delay(this->getDureePoint());
};