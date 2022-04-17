#pragma once
#include <Statistique.h>
#include <Action.h>

class ActionAfficherStatistiqueConsole : public Action
{
    private:
        Statistique* m_statistique;

    public:
        ActionAfficherStatistiqueConsole(Statistique* p_statistique);
        void executer();
};
