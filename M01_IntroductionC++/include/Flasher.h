#pragma once
class Flasher
{
    private: 
        int m_pinDEL;
        int m_dureeAllumeeEteinte;

    public:
        Flasher(int p_pinDEL, int dureeAllumeeEteinte);
        void FaireClignoter(int p_nombreCycless);

        // Construction fait par copie
        Flasher(const Flasher& p_aCopier);

        // Opérateur d'affectation
        Flasher& operator=(const Flasher& p_source);
};