#pragma once
#include "FeuxAutos.h"
#include "FeuxPietons.h"
#include "Statistique.h"
#include "Bouton.h"

class IntersectionRoutiere
{
    private:
        FeuxAutos* m_feuxAutos;
        FeuxPietons* m_feuxPietons;
        Bouton* m_boutonPieton1;
        Bouton* m_boutonPieton2;
        Statistique* m_statistique;
        const unsigned short tempsLumiereVerte = 30000;
        const unsigned short tempsLumiereJaune = 5000;
        unsigned short m_tempsLumiereRouge;
        const unsigned short tempsParDefautLumiereRouge = 15000;
        const unsigned short tempsPassagePieton = 20000;
        const unsigned short tempsTamponApresPieton = 10000;
        unsigned short m_tempsTotalCycle;
        unsigned long m_dateDebutCycle;
        bool m_passagePietonEnCours;
        bool m_demandePassagePieton;
        void desactiverDemandePassagePieton();
        void allongerTempsLumiereRouge();
        void diminuerTempsLumiereRouge();
        void mettreAJourTempsTotalCycle();
    
    public:
        IntersectionRoutiere(FeuxAutos* p_feuxAutos, FeuxPietons* p_feuxPietons, Bouton* p_boutonPieton1, Bouton* p_boutonPieton2, Statistique* p_statistique);
        void activerDemandePassagePieton();
        void loop();
};
