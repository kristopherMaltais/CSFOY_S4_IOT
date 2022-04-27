#include <ActionReinitialiser.h>
#include <Chronometre.h>

ActionReinitialiser::ActionReinitialiser(Chronometre* p_chronometre) : m_chronometre(p_chronometre)
{
}

void ActionReinitialiser::executer()
{
    this->m_chronometre->reinitialiser();
}