#pragma once
#include <Arduino.h>
#include <EEPROM.h>

class Statistique
{
    private:
        unsigned long int m_nombreCyclesAuto;
        unsigned long int m_nombreCyclesPieton;
        const short locationAdresseEEPROMAuto = 1020;
        const short locationAdresseEEPROMPieton = 1022;
        const unsigned long int nombreEcritureLimite = 95000;
        const short adresseParDefautAuto = 0;
        const short adresseParDefautPieton = 1012;
        const short valeurParDefautCaseMemoireEEPROM = 0;
        const short limiteAvertissementEEPROMRemplacement = 24;
        const short pasChangementAdresseMemoire = 9;
        const short pasLectureNombreEcriture = 4; 
        void recupererDonneesEEPROM();
        void decalerAdresseEEPROMAuto();
        void decalerAdresseEEPROMPieton();
        void avertissementChangementEEPROM();
        unsigned long int getNombreEcriture(short p_adresseDebutSection);

    public:
        Statistique();
        double calculerPourcentage();
        void incrementerNombreCyclesAuto();
        void incrementerNombreCyclesPieton();
        short getAdresseEEPROMauto();
        short getAdresseEEPROMpieton();
};
