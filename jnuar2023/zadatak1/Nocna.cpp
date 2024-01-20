#include "Nocna.h"

Nocna::Nocna()
    : Karta()
{
    brDanaVazenja = 0;
    brNociVazenja = 0;
    osnovica = 0;
}

Nocna::Nocna(int IDkarte, int redniBrDana, double popust, int brDanaVazenja, int brNociVazenja, double osnovica)
    : Karta(IDkarte, redniBrDana, popust)
{
    this->brDanaVazenja = brDanaVazenja;
    this->brNociVazenja = brNociVazenja;
    this->osnovica = osnovica;
}

Nocna::Nocna(const Nocna& obj)
    : Karta(obj)
{
     this->brDanaVazenja=obj.brDanaVazenja;
     this->brNociVazenja=obj.brNociVazenja;
     this->osnovica=obj.osnovica;
}

double Nocna::cenaKarte()
{
    return osnovica + zbirniPopust();
}

double Nocna::zbirniPopust()
{
    double s = 0;
    return s += (this->popust + this->brNociVazenja) * (double)1 / 50;
}

Karta* Nocna::getCopy()
{
    return new Nocna(*this);
}

void Nocna::prikaziPodatke(ostream& out)
{
    out << "Broj karte: " << IDkarte << ", Vazi od: " << redniBrDana << ", Popust: "
        << popust << ", Vazi jos: " << brDanaVazenja << ", Br. noci: " << brNociVazenja
        << ", Cena karte: " << cenaKarte() << endl;
}
