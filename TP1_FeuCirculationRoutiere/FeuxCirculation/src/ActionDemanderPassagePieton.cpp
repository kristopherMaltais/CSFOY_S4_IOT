#include <ActionDemanderPassagePieton.h>

ActionDemanderPassagePieton::ActionDemanderPassagePieton()
{
    ;
}

void ActionDemanderPassagePieton::setIntersectionRoutiere(IntersectionRoutiere* p_intersectionRoutiere)
{
    this->m_intersectionRoutiere = p_intersectionRoutiere;
}

void ActionDemanderPassagePieton::executer()
{
    this->m_intersectionRoutiere->activerDemandePassagePieton();
}
