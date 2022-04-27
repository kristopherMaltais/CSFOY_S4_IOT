#pragma once
#include <Affichage4DigitsProxy.h>
#include <Arduino.h>

class Affichage4Digits
{
    private:
        Affichage4DigitsProxy* m_proxy;
        int m_compteur;

    public:
        Affichage4Digits(Affichage4DigitsProxy* p_proxy);
        void afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4);
        void afficherEntier(uint16_t p_valeur);
        uint16_t valeurSegment(uint8_t p_valeurBinaire);
        void afficherBinaire(uint8_t p_entier);
        void afficherDecimal(int p_entier);
        void incrementerCompteur();
        void afficherCompteur();

};