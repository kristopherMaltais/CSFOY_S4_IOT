#pragma once
#include <LCD1602Proxy.h>
#include <Arduino.h>

class LCD1602
{
    private:
        LCD1602Proxy* m_proxy;
        
    public:
        LCD1602(LCD1602Proxy* p_proxy);
        void definirPositionCurseur(int p_colonne, int p_ligne) const;
        void afficher(String& p_texte) const;
        void effacer() const;
};