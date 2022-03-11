#include <PassageParametres.h>
#include <Arduino.h>
#include <Flasher.h>

void PassageDeParametres1(int p_v1, int &p_r1, int *p_p1)
{
    Serial.println("int p_v1 (int * : 0x" + String((uint16_t)(&p_v1), HEX) + ") =" + String(p_v1));
    Serial.println("int &p_r1 (int * : 0x" + String((uint16_t)(&p_r1), HEX) + ") =" + String(p_r1));
    Serial.println("int *p_p1 (int ** : 0x" + String((uint16_t)(&p_p1), HEX) + ") adresse : 0x" + String((uint16_t)(p_p1), HEX) + " = " + String(*p_p1));
}

void PassageDeParametres2(int*& p_referencePointeur, int** p_pointeurPointeur)
{
    Serial.println("DURANT L'APPEL DE LA MÉTHODE: ");

    // Modifier valeur par pointer-pointer
    Serial.println("int p_referencePointeur (int*& : 0x" + String((uint16_t)(&p_referencePointeur), HEX) + ") =" + String(*p_referencePointeur));
    p_referencePointeur = new int;
    *p_referencePointeur = 10;

    // Modifier valeur par pointer-ref
    Serial.println("int p_pointeurPointeur (int** : 0x" + String((uint16_t)(&p_pointeurPointeur), HEX) + ") =" + String(**p_pointeurPointeur));
    *p_pointeurPointeur = new int;
    **p_pointeurPointeur = 20;

    Serial.println("RESULTAT À LA FIN DE LA MÉTHODE: ");
    Serial.println("int p_referencePointeur (int*& : 0x" + String((uint16_t)(&p_referencePointeur), HEX) + ") =" + String(*p_referencePointeur));
    Serial.println("int p_pointeurPointeur (int** : 0x" + String((uint16_t)(&p_pointeurPointeur), HEX) + ") =" + String(**p_pointeurPointeur));


}


// Exercice 3.1.2
void passageDeParametresCopie(Flasher p_flasher)
{
    Serial.println("Par copie - Flasher p_flasher: " + String((uint16_t)(&p_flasher), HEX));

}

// Exercice 3.1.3
void passageDeParametresReference(Flasher& p_flasher)
{
    Serial.println("Par reference - Flasher& p_flasher: " + String((uint16_t)(&p_flasher), HEX));
}

// Exercice 3.1.4
void passageDeParametresPointeur(Flasher* p_flasher)
{
    Serial.println("Par Pointeur - Flasher* p_flasher: " + String((uint16_t)(p_flasher), HEX));
}