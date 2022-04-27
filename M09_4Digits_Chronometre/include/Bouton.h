#pragma once
#include <Arduino.h>
#include <Action.h>

class Bouton
{
    private:
        uint8_t m_pin;
        Action* m_actionBoutonPresse;
        const int delaiMinimumPression = 25;
        const int delaiMinimumLonguePression = 3000;
        unsigned long m_dateDernierChangement;
        int m_dernierEtat;
        int m_dernierEtatStable;

    public:
        Bouton(uint8_t p_pin, Action* p_actionBoutonPresse);
        void tick();
};