#pragma once
#include <Action.h>
#include <Chronometre.h>


class ActionStartStop : public Action
{
    private:
        Chronometre* m_chronometre;
        
    public:
        ActionStartStop(Chronometre* p_chronometre);
        void executer();
};