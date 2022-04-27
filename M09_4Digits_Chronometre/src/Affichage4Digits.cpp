#include <Affichage4Digits.h>
#include <Affichage4DigitsProxy.h>

Affichage4Digits::Affichage4Digits(Affichage4DigitsProxy* p_proxy)
{
    this->m_proxy = p_proxy;
}

void Affichage4Digits::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3, uint8_t p_d4)
{
    this->m_proxy->afficher(p_d1, p_d2, p_d3, p_d4);
}

uint16_t Affichage4Digits::valeurSegment(uint8_t p_valeur)
{
    uint16_t valeurSegment;

    switch(p_valeur)
    {
        case 0:
            valeurSegment = 0b00111111;
            break;
        case 1:
            valeurSegment = 0b00000110;
            break;
        case 2:
            valeurSegment = 0b01011011;
            break;
        case 3:
            valeurSegment = 0b01001111;
            break;
        case 4:
            valeurSegment = 0b01100110;
            break;
        case 5:
            valeurSegment = 0b01101101;
            break;
        case 6:
            valeurSegment = 0b01111101;
            break;
        case 7:
            valeurSegment = 0b00000111;
            break;
        case 8:
            valeurSegment = 0b01111111;
            break;
        case 9:
            valeurSegment = 0b01100111;
            break;

        return valeurSegment;
    }

    return valeurSegment;
}

void Affichage4Digits::afficherDecimal(int p_entier)
{
    int resultat;
    int puissance = 10;
    int valeurs[4] = {this->valeurSegment(0), this->valeurSegment(0), this->valeurSegment(0), this->valeurSegment(0)};
    int positionTableau = 0;

    while(p_entier > 0)
    {
        resultat = p_entier % puissance;
        p_entier /= puissance;
        valeurs[positionTableau] = this->valeurSegment(resultat);
        positionTableau++;
    }

    this->m_proxy->afficher(valeurs[3], valeurs[2], valeurs[1], valeurs[0]);
}
