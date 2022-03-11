// Fait avec Gabriel Tremblay
#include <Arduino.h>
#include <MorseSerie.h>


void MorseSerie::afficherPoint()
{
    Serial.println("- "); 
}

void MorseSerie::afficherTrait()
{
    Serial.println("--- "); 
}