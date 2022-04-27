#pragma once
#include <Action.h>
#include <Affichage4Digits.h>


class ActionIncrementerCompteur : public Action
{
    private:
        Affichage4Digits* m_affichage4Digits;
        
    public:
        ActionIncrementerCompteur(Affichage4Digits* p_affichage4Digits);
        void executer();
};