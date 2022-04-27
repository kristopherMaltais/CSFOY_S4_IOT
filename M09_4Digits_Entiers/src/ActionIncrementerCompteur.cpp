#include <ActionIncrementerCompteur.h>
#include <Affichage4Digits.h>

ActionIncrementerCompteur::ActionIncrementerCompteur(Affichage4Digits* p_affichage4Digits) : m_affichage4Digits(p_affichage4Digits)
{
}

void ActionIncrementerCompteur::executer()
{
    this->m_affichage4Digits->incrementerCompteur();
}