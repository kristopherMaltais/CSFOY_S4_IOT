#pragma once
#include <LCD1602.h>

class Program
{
    private:
        LCD1602* m_LCD;
        
    public:
        Program();
        void loop();
};