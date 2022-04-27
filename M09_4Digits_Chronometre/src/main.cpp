#include <Arduino.h>
#include <Chronometre.h>

Chronometre* chronometre;

void setup() {
  chronometre = new Chronometre();
}

void loop() {
  chronometre->tick();
}