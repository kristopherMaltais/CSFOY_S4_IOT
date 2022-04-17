#include "ActionReinitialiserStatistique.h"

ActionReinitialiserStatistique::ActionReinitialiserStatistique(Statistique* p_statistique) : m_statistique(p_statistique)
{
    ;
}

void ActionReinitialiserStatistique::executer()
{
    unsigned long int valeurParDefaut = 0;
    EEPROM.put(this->m_statistique->getAdresseEEPROMauto(), valeurParDefaut);
    EEPROM.put(this->m_statistique->getAdresseEEPROMpieton(), valeurParDefaut);
}
