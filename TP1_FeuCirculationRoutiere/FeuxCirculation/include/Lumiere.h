#pragma once
#include <Arduino.h>

class Lumiere
{
    private:
        uint8_t m_pin;
        
    public:
        Lumiere(uint8_t p_pin);
        void allumer();
        void eteindre();
};
