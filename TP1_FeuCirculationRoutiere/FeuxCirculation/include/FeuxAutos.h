#pragma once
#include <Arduino.h>
#include <Lumiere.h>

class FeuxAutos
{
    private:
        Lumiere* m_lumiereVerte;
        Lumiere* m_lumiereJaune;
        Lumiere* m_lumiereRouge;

    public:
        FeuxAutos(Lumiere* p_lumiereVerte, Lumiere* p_lumiereJaune, Lumiere* p_lumiereRouge);
        void activerLumiereVerte();
        void activerLumiereJaune();
        void activerLumiereRouge();
};
