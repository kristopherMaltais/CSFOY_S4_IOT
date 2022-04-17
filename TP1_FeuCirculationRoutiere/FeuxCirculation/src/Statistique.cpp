#include "Statistique.h"
#include <Arduino.h>

Statistique::Statistique()
{
    if (this->getAdresseEEPROMauto() == this->valeurParDefautCaseMemoireEEPROM)
    {
        EEPROM.put(this->locationAdresseEEPROMAuto, this->adresseParDefautAuto);
    }

    if (this->getAdresseEEPROMpieton() == this->valeurParDefautCaseMemoireEEPROM)
    {
        EEPROM.put(this->locationAdresseEEPROMPieton, this->adresseParDefautPieton);
    }

    this->recupererDonneesEEPROM();
}

void Statistique::recupererDonneesEEPROM()
{
    this->m_nombreCyclesAuto = EEPROM.get(this->getAdresseEEPROMauto(), this->m_nombreCyclesAuto);
    this->m_nombreCyclesPieton = EEPROM.get(this->getAdresseEEPROMpieton(), this->m_nombreCyclesPieton);
}

double Statistique::calculerPourcentage()
{
    this->recupererDonneesEEPROM();
    return this->m_nombreCyclesPieton != 0 ? ((double)((double)this->m_nombreCyclesPieton / (double)this->m_nombreCyclesAuto)) * 100.00 : 0.00;
}

void Statistique::incrementerNombreCyclesAuto() 
{
    short adresseEEPROMauto = this->getAdresseEEPROMauto();
    unsigned long int nbCyclesAuto = EEPROM.get(adresseEEPROMauto, this->m_nombreCyclesAuto);

    if (getNombreEcriture(adresseEEPROMauto) >= this->nombreEcritureLimite)
    {
        this->decalerAdresseEEPROMAuto();
        adresseEEPROMauto = this->getAdresseEEPROMauto();
        EEPROM.put(adresseEEPROMauto + this->pasLectureNombreEcriture, 0); // Remettre le nombre d'écriture à 0
    }

    unsigned long int typeValeur = 0;
    EEPROM.put(adresseEEPROMauto, nbCyclesAuto + 1);
    EEPROM.put(adresseEEPROMauto + this->pasLectureNombreEcriture, EEPROM.get(adresseEEPROMauto + this->pasLectureNombreEcriture, typeValeur) + 1);
}

void Statistique::incrementerNombreCyclesPieton()
{
    short adresseEEPROMpieton = this->getAdresseEEPROMpieton();
    unsigned long int nbCyclesPietons = EEPROM.get(adresseEEPROMpieton, this->m_nombreCyclesPieton);

    if (getNombreEcriture(adresseEEPROMpieton) >= this->nombreEcritureLimite)
    {
        this->decalerAdresseEEPROMPieton();
        adresseEEPROMpieton = this->getAdresseEEPROMpieton();
        EEPROM.put(adresseEEPROMpieton + this->pasLectureNombreEcriture, 0); // Remettre le nombre d'écriture à 0
    }

    unsigned long int typeValeur = 0;
    EEPROM.put(adresseEEPROMpieton, nbCyclesPietons + 1);
    EEPROM.put(adresseEEPROMpieton + this->pasLectureNombreEcriture, EEPROM.get(adresseEEPROMpieton + this->pasLectureNombreEcriture, typeValeur) + 1);
}

short Statistique::getAdresseEEPROMauto()
{
    short typeValeur = 0;
    return EEPROM.get(this->locationAdresseEEPROMAuto, typeValeur);
}

short Statistique::getAdresseEEPROMpieton() 
{
    short typeValeur = 0;
    return EEPROM.get(this->locationAdresseEEPROMPieton, typeValeur);
}

unsigned long int Statistique::getNombreEcriture(short p_adresseDebutSection)
{
    unsigned long int typeValeur = 0;
    return EEPROM.get(p_adresseDebutSection + this->pasLectureNombreEcriture, typeValeur);
}

void Statistique::decalerAdresseEEPROMAuto()
{
    if(this->getAdresseEEPROMpieton() - this->getAdresseEEPROMauto() <= this->limiteAvertissementEEPROMRemplacement)
    {
        this->avertissementChangementEEPROM();
    }

    short typeValeur = 0;
    EEPROM.put(this->locationAdresseEEPROMAuto, EEPROM.get(this->locationAdresseEEPROMAuto, typeValeur) + this->pasChangementAdresseMemoire);
}

void Statistique::decalerAdresseEEPROMPieton()
{
    if(this->getAdresseEEPROMpieton() - this->getAdresseEEPROMauto() <= this->limiteAvertissementEEPROMRemplacement)
    {
        this->avertissementChangementEEPROM();
    }

    short typeValeur = 0;
    EEPROM.put(this->locationAdresseEEPROMPieton, EEPROM.get(this->locationAdresseEEPROMPieton, typeValeur) - this->pasChangementAdresseMemoire);
}

void Statistique::avertissementChangementEEPROM()
{
    Serial.println("*** Changement de la carte Arduino Uno nécessaire d'ici 4 mois ***");
}