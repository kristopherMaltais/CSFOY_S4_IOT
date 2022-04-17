#include "Program.h"

Lumiere* lumiereAutoVerte;
Lumiere* lumiereAutoJaune;
Lumiere* lumiereAutoRouge;

Lumiere* lumierePietonVerte;
Lumiere* lumierePietonRouge;

FeuxAutos* feuxAuto;

ActionDemanderPassagePieton* actionDemanderPassagePieton;
Bouton* boutonCote1;
Bouton* boutonCote2;
ActionNulle* actionBoutonPresseLongtempsNulle;
FeuxPietons* feuxPietons;

ActionAfficherStatistiqueConsole* actionAfficherStatistique;
ActionReinitialiserStatistique* actionReinitialiserStatistique;
Statistique* statistique;
Bouton* boutonStatistique;
IntersectionRoutiere* intersectionRoutiere;

Program::Program() 
{
    this->setup();
}

void Program::setup() 
{
    Serial.begin(9600);
    lumiereAutoVerte = new Lumiere(3);
    lumiereAutoJaune = new Lumiere(4);
    lumiereAutoRouge = new Lumiere(5);

    lumierePietonVerte = new Lumiere(6);
    lumierePietonRouge = new Lumiere(7);

    feuxAuto = new FeuxAutos(lumiereAutoVerte, lumiereAutoJaune, lumiereAutoRouge);

    actionDemanderPassagePieton = new ActionDemanderPassagePieton();
    actionBoutonPresseLongtempsNulle = new ActionNulle();
    boutonCote1 = new Bouton(10, actionDemanderPassagePieton, actionBoutonPresseLongtempsNulle);
    boutonCote2 = new Bouton(11, actionDemanderPassagePieton, actionBoutonPresseLongtempsNulle);
    feuxPietons = new FeuxPietons(lumierePietonVerte, lumierePietonRouge);

    statistique = new Statistique();
    actionAfficherStatistique = new ActionAfficherStatistiqueConsole(statistique);
    actionReinitialiserStatistique = new ActionReinitialiserStatistique(statistique);
    boutonStatistique = new Bouton(12, actionAfficherStatistique, actionReinitialiserStatistique);

    intersectionRoutiere = new IntersectionRoutiere(feuxAuto, feuxPietons, boutonCote1, boutonCote2, statistique);

    actionDemanderPassagePieton->setIntersectionRoutiere(intersectionRoutiere);

    Serial.println("Pourcentage de passage piétons VS autos = " + String(statistique->calculerPourcentage()) + "%");
}

void Program::loop() 
{
    intersectionRoutiere->loop();
    boutonCote1->tick();
    boutonCote2->tick();
    boutonStatistique->tick();
}
