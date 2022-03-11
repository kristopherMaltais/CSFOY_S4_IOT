// Fait avec Gabriel Tremblay
#pragma once
#include <Morse.h>

class MorseSerie : public Morse
{
    public:
        using Morse::Morse;
        virtual void afficherPoint();
        virtual void afficherTrait();
};