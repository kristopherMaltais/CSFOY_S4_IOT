#include <ActionStartStop.h>
#include <Affichage4Digits.h>

ActionStartStop::ActionStartStop(Chronometre* p_chronometre) : m_chronometre(p_chronometre)
{
}

void ActionStartStop::executer()
{
    this->m_chronometre->demarrerArreter();
}