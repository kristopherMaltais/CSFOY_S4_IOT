#pragma once
class DEL
{
    private:
        int m_pinDEL;
    public: 
        DEL(const int& p_pinDEL);
        void allume() const;
        void eteindre() const;
};