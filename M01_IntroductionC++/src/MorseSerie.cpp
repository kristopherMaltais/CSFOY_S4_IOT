// Fait avec Gabriel Tremblay
#include <Arduino.h>
#include <MorseSerie.h>


void MorseSerie::afficherPoint()
{
    Serial.print("- "); 
}

void MorseSerie::afficherTrait()
{
    Serial.print("--- "); 
}