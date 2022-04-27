#pragma once
#include <Affichage4DigitsProxy.h>
#include <Arduino.h>

class Affichage4Digits
{
    private:
        Affichage4DigitsProxy* m_proxy;
        uint8_t secondeUnite;
        uint8_t secondeDizaine;
        uint8_t minuteUnite;
        uint8_t minuteDizaine;

    public:
        Affichage4Digits(Affichage4DigitsProxy* p_proxy);
        void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4);
        uint16_t valeurSegment(uint8_t p_valeurBinaire);
        void afficherDecimal(int p_entier);
};