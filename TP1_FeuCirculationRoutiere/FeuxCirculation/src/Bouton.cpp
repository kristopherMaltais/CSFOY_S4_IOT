#include <Bouton.h>

Bouton::Bouton(uint8_t p_pin, Action* p_actionBoutonPresse, Action* p_actionBoutonPresseLongtemps) : m_pin(p_pin), m_actionBoutonPresse(p_actionBoutonPresse), m_actionBoutonPresseLongtemps(p_actionBoutonPresseLongtemps), m_dateDernierChangement(0), m_dernierEtat(HIGH), m_dernierEtatStable(HIGH)
{
    pinMode(this->m_pin, INPUT);
}

void Bouton::tick() // Code inspiré de ce document pdf : https://github.com/PiFou86/420-W48-SF/blob/main/Module06_ProgrammationEntreesNumeriques/Module06_ProgrammationDesEntreesNumeriques_2_2.pdf
{
  int etatBouton = digitalRead(this->m_pin);
  long dateActuelle = millis();
  
  if (etatBouton != this->m_dernierEtat)
  {
    this->m_dateDernierChangement = dateActuelle;
    this->m_dernierEtat = etatBouton;
  }

  if (dateActuelle - this->m_dateDernierChangement > this->delaiMinimumPression)
  {
    if (this->m_dernierEtatStable == LOW && etatBouton == HIGH)
    {
      this->m_actionBoutonPresse->executer();
    }

    this->m_dernierEtatStable = etatBouton;
  }

  if (etatBouton == LOW && dateActuelle - this->m_dateDernierChangement == this->delaiMinimumLonguePression)
  {
    this->m_actionBoutonPresseLongtemps->executer();
  }
}
