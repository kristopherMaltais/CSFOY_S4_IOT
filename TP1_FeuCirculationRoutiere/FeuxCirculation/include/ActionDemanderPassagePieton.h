#pragma once
#include <Action.h>
#include "IntersectionRoutiere.h"

class ActionDemanderPassagePieton : public Action
{
    private:
        IntersectionRoutiere* m_intersectionRoutiere;
        
    public:
        ActionDemanderPassagePieton();
        void setIntersectionRoutiere(IntersectionRoutiere* p_intersectionRoutiere);
        void executer();
};
