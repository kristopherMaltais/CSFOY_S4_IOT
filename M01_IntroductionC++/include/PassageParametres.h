#pragma once
#include <Flasher.h>

void PassageDeParametres1(int p_v1, int &p_r1, int *p_p1);
void PassageDeParametres2(int*& p_referencePointeur, int** p_pointeurPointeur);

// Exercice 3.1.2
void passageDeParametresCopie(Flasher p_flasher);

// Exercice 3.1.3
void passageDeParametresReference(Flasher& p_flasher);

// Exercice 3.1.4
void passageDeParametresPointeur(Flasher* p_flasher);
