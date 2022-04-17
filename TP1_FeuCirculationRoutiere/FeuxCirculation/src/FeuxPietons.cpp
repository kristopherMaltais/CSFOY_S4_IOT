#include "FeuxPietons.h"

FeuxPietons::FeuxPietons(Lumiere* p_lumiereVerte, Lumiere* p_lumiereRouge) : m_lumiereVerte(p_lumiereVerte), m_lumiereRouge(p_lumiereRouge)
{
    this->desactiverPassage();
}

void FeuxPietons::activerPassage() 
{
    this->m_lumiereRouge->eteindre();
    this->m_lumiereVerte->allumer();
}

void FeuxPietons::desactiverPassage()
{
    this->m_lumiereVerte->eteindre();
    this->m_lumiereRouge->allumer();
}
