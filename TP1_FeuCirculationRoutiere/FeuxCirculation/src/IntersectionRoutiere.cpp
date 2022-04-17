#include <Arduino.h>
#include "IntersectionRoutiere.h"
#include "FeuxPietons.h"
#include <EEPROM.h>

IntersectionRoutiere::IntersectionRoutiere(FeuxAutos* p_feuxAutos, FeuxPietons* p_feuxPietons, Bouton* p_boutonPieton1, Bouton* p_boutonPieton2, Statistique* p_statistique) : m_feuxAutos(p_feuxAutos), m_feuxPietons(p_feuxPietons), m_boutonPieton1(p_boutonPieton1), m_boutonPieton2(p_boutonPieton2), m_statistique(p_statistique), m_tempsLumiereRouge(tempsParDefautLumiereRouge), m_passagePietonEnCours(false), m_demandePassagePieton(false)
{
    this->m_dateDebutCycle = millis();
    this->mettreAJourTempsTotalCycle();
}

void IntersectionRoutiere::loop() 
{   
    unsigned long dateActuelle = millis();
    unsigned long differenreDepuisDateDebut = dateActuelle - this->m_dateDebutCycle;

    if (this->m_passagePietonEnCours && differenreDepuisDateDebut > this->tempsPassagePieton)
    {
        this->m_passagePietonEnCours = false;
        this->m_feuxPietons->desactiverPassage();
        this->desactiverDemandePassagePieton();
    }

    else if (differenreDepuisDateDebut <= this->m_tempsLumiereRouge)
    {
        this->m_feuxAutos->activerLumiereRouge();
    }

    else if (differenreDepuisDateDebut <= this->m_tempsLumiereRouge + this->tempsLumiereVerte)
    {
        this->m_feuxAutos->activerLumiereVerte();
    }

    else if (differenreDepuisDateDebut <= this->m_tempsTotalCycle) 
    {
        this->m_feuxAutos->activerLumiereJaune();
    }

    else
    {
        this->m_dateDebutCycle = dateActuelle;
      
        if (this->m_tempsLumiereRouge != tempsParDefautLumiereRouge)
        {
            this->m_tempsLumiereRouge = tempsParDefautLumiereRouge;
        }

        if (this->m_demandePassagePieton == true)
        {
            this->m_demandePassagePieton = false;
            this->m_passagePietonEnCours = true;
            this->m_feuxPietons->activerPassage();
            this->allongerTempsLumiereRouge();
            this->m_statistique->incrementerNombreCyclesPieton();
        }  

        this->m_statistique->incrementerNombreCyclesAuto();   

        this->mettreAJourTempsTotalCycle();
    }
}

void IntersectionRoutiere::activerDemandePassagePieton() 
{
    this->m_demandePassagePieton = true;
}

void IntersectionRoutiere::desactiverDemandePassagePieton()
{
    this->m_demandePassagePieton = false;
}

void IntersectionRoutiere::allongerTempsLumiereRouge()
{
    this->m_tempsLumiereRouge += this->tempsTamponApresPieton;
}

void IntersectionRoutiere::diminuerTempsLumiereRouge()
{
    this->m_tempsLumiereRouge -= this->tempsTamponApresPieton;
}

void IntersectionRoutiere::mettreAJourTempsTotalCycle()
{
    this->m_tempsTotalCycle = this->tempsLumiereVerte + this->tempsLumiereJaune + this->m_tempsLumiereRouge;
}
