#include <GestionDELInterne.h>
#include <Arduino.h>
#include <Configuration.h>

void allumerDELInterne(int p_duree)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_duree);
}

void eteindreDELInterne(int p_duree)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_duree);
}

void AfficherSEnMorse()
{
    int repetition;
    for(repetition = 0; repetition < 3; repetition++)
    {
        allumerDELInterne(TRAIT_COURT);
        eteindreDELInterne(PAUSE_ENTRE_TRAIT);
    }
}

void AffichierOEnMorse()
{
    int repetition;
    for(repetition = 0; repetition < 3; repetition++)
    {
        allumerDELInterne(TRAIT_LONG);
        eteindreDELInterne(PAUSE_ENTRE_TRAIT);
    }
}

void AfficherSOSEnMorse()
{
    AfficherSEnMorse();
    AffichierOEnMorse();
    AfficherSEnMorse();
    delay(DELAIS_FIN);
}