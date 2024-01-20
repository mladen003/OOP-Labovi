#include "Dnevna.h"

Dnevna::Dnevna()
    : Karta()
{
    brDanaVazenja = 0;
    osnovica = 0;
}

Dnevna::Dnevna(int IDkarte, int redniBrDana, double popust, int brDanaVazenja, double osnovica)
    : Karta(IDkarte, redniBrDana, popust)
{
    this->brDanaVazenja = brDanaVazenja;
    this->osnovica = osnovica;
}

Dnevna::Dnevna(const Dnevna& obj)
    : Karta(obj)
{
    this->brDanaVazenja=obj.brDanaVazenja;
    this->osnovica=obj.osnovica;
}

double Dnevna::cenaKarte()
{
    return zbirniPopust() + this->osnovica;
}

double Dnevna::zbirniPopust()
{
    double s = 0;;
    return s += (this->popust + this->brDanaVazenja) * (double)1 / 50;
}

Karta* Dnevna::getCopy()
{
    return new Dnevna(*this);
}

void Dnevna::prikaziPodatke(ostream& out)
{
    out << "Broj karte: " << IDkarte << ", Vazi od: " << redniBrDana << ", Popust: " 
        << popust << ", Vazi jos: " << brDanaVazenja << ", Cena karte: " << cenaKarte() << endl;
}

