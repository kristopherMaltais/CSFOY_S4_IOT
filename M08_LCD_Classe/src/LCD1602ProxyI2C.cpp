#include <LCD1602ProxyI2C.h>

LCD1602ProxyI2C::LCD1602ProxyI2C() 
{
    this->m_LCD = new LiquidCrystal_I2C(0x27, 16, 2);
    this->m_LCD->init();
    this->m_LCD->backlight();
}

void LCD1602ProxyI2C::definirPositionCurseur(int p_colonne, int p_ligne) const
{
    this->m_LCD->setCursor(1, 16);
}

void LCD1602ProxyI2C::afficher(const String& p_texte) const
{
    this->m_LCD->print(p_texte);
}

void LCD1602ProxyI2C::effacer() const
{
    this->m_LCD->clear();
}