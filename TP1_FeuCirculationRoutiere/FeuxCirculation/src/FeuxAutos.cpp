#include <FeuxAutos.h>
#include <Arduino.h>

FeuxAutos::FeuxAutos(Lumiere* p_lumiereVerte, Lumiere* p_lumiereJaune, Lumiere* p_lumiereRouge): m_lumiereVerte(p_lumiereVerte), m_lumiereJaune(p_lumiereJaune), m_lumiereRouge(p_lumiereRouge)
{
    ;
}

void FeuxAutos::activerLumiereVerte()
{
    this->m_lumiereJaune->eteindre();
    this->m_lumiereRouge->eteindre();
    this->m_lumiereVerte->allumer();
}

void FeuxAutos::activerLumiereJaune()
{
    this->m_lumiereVerte->eteindre();
    this->m_lumiereRouge->eteindre();
    this->m_lumiereJaune->allumer();
}

void FeuxAutos::activerLumiereRouge()
{
    this->m_lumiereVerte->eteindre();
    this->m_lumiereJaune->eteindre();
    this->m_lumiereRouge->allumer();
}
