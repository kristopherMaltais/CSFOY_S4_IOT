#include <Program.h>
#include <Affichage4DigitsProxy.h>
#include <Affichage4DigitsProxyTM1637.h>
#include <Program.h>
#include <Bouton.h>
#include <ActionIncrementerCompteur.h>

long dataDernierChangement = millis();
int entierAAfficher = 0;

Bouton* bouton;
Action* action;

Program::Program()
{
    Affichage4DigitsProxy* affichage4Digits = new Affichage4DigitsProxyTM1637(2, 3);
    this->m_affichage4Digits = new Affichage4Digits(affichage4Digits);
    action = new ActionIncrementerCompteur(this->m_affichage4Digits);
    bouton = new Bouton(4, action);
}

void Program::loop()
{
    // Étape 1 afficher 1010
    //this->m_affichage4Digits->afficher(0b00000110, 0b00111111, 0b00000110, 0b00111111);

    // Étape 2 compteur binaire
    // long dateActuelle = millis();

    // if(dateActuelle - dataDernierChangement >= 1000)
    // {
    //     this->m_affichage4Digits->afficherBinaire(entierAAfficher);
    //     dataDernierChangement = dateActuelle;
    //     entierAAfficher++;
    //     entierAAfficher = entierAAfficher > 15 ? 0 : entierAAfficher;
    // }

    // Étape 3 compteur decimal
    // long dateActuelle = millis();

    // if(dateActuelle - dataDernierChangement >= 1)
    // {
    //     this->m_affichage4Digits->afficherDecimal(entierAAfficher);
    //     dataDernierChangement = dateActuelle;
    //     entierAAfficher++;
    //     entierAAfficher = entierAAfficher > 9999 ? 0 : entierAAfficher;
    // }

    // Exercice 2 - Compteur de pressions
    this->m_affichage4Digits->afficherCompteur();
    bouton->tick();
}

