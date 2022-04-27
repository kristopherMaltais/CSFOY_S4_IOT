#include <Bouton.h>

Bouton::Bouton(uint8_t p_pin, Action* p_actionBoutonPresse) : m_pin(p_pin), m_actionBoutonPresse(p_actionBoutonPresse), m_dateDernierChangement(0), m_dernierEtat(HIGH), m_dernierEtatStable(HIGH)
{
    pinMode(this->m_pin, INPUT);
}

void Bouton::tick()
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
}