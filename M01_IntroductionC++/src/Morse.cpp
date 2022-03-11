// Fait avec Gabriel Tremblay
#include "Morse.h"

Morse::Morse(int p_dureePoint) : m_dureePoint(p_dureePoint) 
{

};

void Morse::afficherSos() 
{
    const int nbAppels = 3;
    for (int index = 0; index < nbAppels; index++)
    {
        this->afficherPoint();
    }
    for (int index = 0; index < nbAppels; index++)
    {
        this->afficherTrait();
    }
    for (int index = 0; index < nbAppels; index++)
    {
        this->afficherPoint();
    }
};

int Morse::getDureePoint() const
{
    return this->m_dureePoint;
};