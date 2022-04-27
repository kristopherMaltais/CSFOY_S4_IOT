#include <chronometre.h>
#include <Affichage4DigitsProxy.h>
#include <Affichage4DigitsProxyTM1637.h>
#include <Bouton.h>
#include <Action.h>
#include <ActionStartStop.h>
#include <ActionReinitialiser.h>

Chronometre::Chronometre()
{
    Affichage4DigitsProxy* affichage4Digits = new Affichage4DigitsProxyTM1637(2, 3);
    this->m_affichage4Digits = new Affichage4Digits(affichage4Digits);
    Action* action1 = new ActionStartStop(this);
    Action* action2 = new ActionReinitialiser(this);
    this->m_boutonReinitialiser = new Bouton(4, action2);
    this->m_boutonStopStart = new Bouton(5, action1);

    this->m_estActive = false;
    this->m_dateDebut = millis();
    this->m_secondeUnite = 0;
    this->m_secondeDizaine = 0;
    this->m_minuteUnite = 0;
    this->m_minuteDizaine = 0;
}

void Chronometre::reinitialiser()
{
    this->m_secondeUnite = 0;
    this->m_secondeDizaine = 0;
    this->m_minuteUnite = 0;
    this->m_minuteDizaine = 0;
}

void Chronometre::demarrerArreter()
{
    this->m_estActive = !this->m_estActive;
}

void Chronometre::tick()
{
    long dateActuelle = millis();
    this->m_boutonStopStart->tick();
    this->m_boutonReinitialiser->tick();
    
    if(this->m_estActive && dateActuelle - this->m_dateDebut > 1000)
    {
        this->m_secondeUnite++;

        if(this->m_secondeUnite == 10)
        {
            this->m_secondeDizaine++;
            this->m_secondeUnite = 0;
        }

        if(this->m_secondeDizaine == 6)
        {
            this->m_minuteUnite++;
            this->m_secondeDizaine = 0;
        }

        if(this->m_minuteUnite == 10)
        {
            this->m_minuteDizaine++;
            this->m_minuteUnite = 0;
        }

        

        this->m_dateDebut = dateActuelle;
    }

    this->m_affichage4Digits->afficher(this->m_affichage4Digits->valeurSegment(this->m_minuteDizaine), this->m_affichage4Digits->valeurSegment(this->m_minuteUnite), this->m_affichage4Digits->valeurSegment(this->m_secondeDizaine), this->m_affichage4Digits->valeurSegment(this->m_secondeUnite));
}

