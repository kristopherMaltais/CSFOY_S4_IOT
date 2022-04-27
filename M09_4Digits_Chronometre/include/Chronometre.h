#pragma once
#include <Affichage4Digits.h>
#include <Bouton.h>
#include <Arduino.h>

class Chronometre
{
    private:
        Affichage4Digits* m_affichage4Digits;
        Bouton* m_boutonStopStart;
        Bouton* m_boutonReinitialiser;
        bool m_estActive;
        long m_dateDebut;

        uint8_t m_secondeUnite;
        uint8_t m_secondeDizaine;
        uint8_t m_minuteUnite;
        uint8_t m_minuteDizaine;

    public:
        Chronometre();
        void reinitialiser();
        void demarrerArreter();
        void tick();

};