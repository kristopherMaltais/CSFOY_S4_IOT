#pragma once
#include <Arduino.h>
#include "Lumiere.h"
#include "FeuxAutos.h"
#include "FeuxPietons.h"
#include "IntersectionRoutiere.h"
#include "Bouton.h"
#include "Action.h"
#include "ActionDemanderPassagePieton.h"
#include "ActionAfficherStatistiqueConsole.h"
#include "ActionReinitialiserStatistique.h"
#include "ActionNulle.h"

class Program 
{
    private:
        void setup();

    public:
        Program();
        void loop();
};
