#pragma once
#include <EEPROM.h>
#include "Action.h"
#include "Statistique.h"

class ActionReinitialiserStatistique : public Action
{
    private:
        Statistique* m_statistique;

    public:
        ActionReinitialiserStatistique(Statistique* p_statistique);
        void executer();
};
