#pragma once
#include <Action.h>
#include <Chronometre.h>


class ActionReinitialiser : public Action
{
    private:
        Chronometre* m_chronometre;
        
    public:
        ActionReinitialiser(Chronometre* p_chronometre);
        void executer();
};