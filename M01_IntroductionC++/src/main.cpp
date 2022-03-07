#include <Arduino.h>
#include <GestionDELInterne.h>
#include <Configuration.h>
#include <PassageParametres.h>
#include <Flasher.h>
#include <DEL.h>


// Flasher flasher(LED_BUILTIN, 500);
void setup()
{ 
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  // Exercice 2.1 - Préambule - Affichage d'information sur le moniteur série
  // int valeur1 = 42;
  // int valeur2 = 13;
  // Serial.println(42);
  // Serial.println("Bonjour à tous!");
  // Serial.println(String(42, HEX));
  // Serial.println("0x" + String(42, HEX));
  // Serial.println("int valeur1 (int * : 0x" + String((uint16_t)(&valeur1), HEX) + ") = " + String(valeur1));
  // Serial.println("int valeur2 (int * : 0x" + String((uint16_t)(&valeur2), HEX) + ") = " + String(valeur2));

  // Exercice 2.2 - Observations
  // Serial.println("Appel de passageDeParametres1");
  // PassageDeParametres1(valeur1, valeur1, &valeur2);

  // Exercice 2.3 - À vous!
  // int* pointer1 = NULL;
  // int* pointer2 = NULL;
  // Serial.println("AVANT APPEL DE LA MÉTHODE: ");
  // Serial.println("int pointer1 (int * : 0x" + String((uint16_t)(&pointer1), HEX) + ") =" + String(*pointer1));
  // Serial.println("int pointer2 (int * : 0x" + String((uint16_t)(&pointer2), HEX) + ") =" + String(*pointer2));
  // PassageDeParametres2(pointer1 ,&pointer2);
  // Serial.println("APRES APPEL DE LA MÉTHODE:");
  // Serial.println("int pointer1 (int * : 0x" + String((uint16_t)(&pointer1), HEX) + ") =" + String(*pointer1));
  // Serial.println("int pointer2 (int * : 0x" + String((uint16_t)(&pointer2), HEX) + ") =" + String(*pointer2));

  // Flasher flasherDuSetup(LED_BUILTIN, 200);
  // flasher = flasherDuSetup;

  // Exercice 3.1.2, 3.1.3, 3.1.4
  // Flasher flasherDuSetup(LED_BUILTIN, 200);
  // Serial.println("Adresse objet passé en paramètre: " + String((uint16_t)(&flasherDuSetup), HEX));
  // passageDeParametresCopie(flasherDuSetup);
  // passageDeParametresReference(flasherDuSetup);
  // passageDeParametresPointeur(&flasherDuSetup);
}

// Flasher flasher(LED_BUILTIN, 500);
// DEL testDel(LED_BUILTIN);
void loop()
{
  // Exercice 1.3 - S.O.S
  // AfficherSOSEnMorse();
  // flasher.FaireClignoter(1);

  // Exercice 3.2 Classe DEL - À vous !
  // testDel.allume();
  // delay(4000);
  // testDel.eteindre();
  // delay(4000);
}