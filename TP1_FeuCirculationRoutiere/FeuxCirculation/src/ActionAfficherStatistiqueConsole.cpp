#include <ActionAfficherStatistiqueConsole.h>

ActionAfficherStatistiqueConsole::ActionAfficherStatistiqueConsole(Statistique* p_statistique) : m_statistique(p_statistique)
{
    ;
}

void ActionAfficherStatistiqueConsole::executer()
{
    Serial.println("Pourcentage de passage piétons VS autos = " + String(this->m_statistique->calculerPourcentage()) + "%");
}
