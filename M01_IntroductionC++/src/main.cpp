#include <Arduino.h>
#include <GestionDELInterne.h>
#include <Configuration.h>

void setup()
{ 
  pinMode(13, OUTPUT);
}

void loop()
{
  AfficherSOSEnMorse();
}