// Fait avec Gabriel Tremblay
#pragma once
#include "Morse.h"

class MorseDEL : public Morse
{
    private:
        int m_pinDEL;

    public:
    using Morse::Morse;
    MorseDEL(int p_dureePoint, int p_pinDEL);
    virtual void afficherPoint();
    virtual void afficherTrait();
};