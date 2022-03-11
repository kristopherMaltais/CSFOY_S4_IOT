// Fait avec Gabriel Tremblay
#pragma once

class Morse
{
    private:
        int m_dureePoint;

    public:
        Morse(int p_dureePoint);
        virtual void afficherPoint() = 0;
        virtual void afficherTrait() = 0;
        void afficherSos ();
        int getDureePoint() const;
};