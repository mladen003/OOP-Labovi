#include "Igracke.h"

Igracke::Igracke()
	: Paketic()
{
	brojAutica = 0;
	tezinaAutica = 0;
	cenaAutica = 0;
}

Igracke::Igracke(int adresa, const char* boja, int brojAutica, double tezinaAutica, double cenaAutica)
	: Paketic(adresa, boja)
{
	this->brojAutica = brojAutica;
	this->tezinaAutica = tezinaAutica;
	this->cenaAutica = cenaAutica;
}

Igracke::Igracke(const Igracke& obj)
	: Paketic(obj)
{
	this->brojAutica = obj.brojAutica;
	this->tezinaAutica = obj.tezinaAutica;
	this->cenaAutica = obj.cenaAutica;
}

double Igracke::cena()
{
	return cenaAutica * brojAutica;
}

void Igracke::prikaz(ostream& out)
{
	out << "Adresa za isporuku: " << this->adresa << ", boja: " << this->boja << ", broj autica: "
		<< brojAutica << ", tezina autica: " << tezina() << ", cena: " << cena();
}

double Igracke::tezina()
{
	return (double)tezinaAutica*brojAutica;
}

Paketic* Igracke::getCopy()
{
	return new Igracke(*this);
}
