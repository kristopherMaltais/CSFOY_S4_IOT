#pragma once
#include <Arduino.h>
#include "Lumiere.h"
#include "Bouton.h"

class FeuxPietons
{
    private:
        Lumiere* m_lumiereVerte;
        Lumiere* m_lumiereRouge;

    public:
        FeuxPietons(Lumiere* p_lumiereVerte, Lumiere* p_lumiereRouge);
        void activerPassage();
        void desactiverPassage();
};
