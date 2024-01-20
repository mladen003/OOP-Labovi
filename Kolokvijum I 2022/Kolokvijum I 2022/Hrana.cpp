#include "Hrana.h"

Hrana::Hrana()
	: Paketic()
{
	brojCokolada = 0;
	tezinaCokolada = 0;
	cenaCokolada = 0;
}

Hrana::Hrana(int adresa, const char* boja, int brojCokolada, double tezinaCokolada, double cenaCokolada)
	: Paketic(adresa, boja)
{
	this->brojCokolada = brojCokolada;
	this->tezinaCokolada = tezinaCokolada;
	this->cenaCokolada = cenaCokolada;
}

Hrana::Hrana(const Hrana& obj)
	: Paketic(obj)
{
	this->brojCokolada = obj.brojCokolada;
	this->tezinaCokolada = obj.tezinaCokolada;
	this->cenaCokolada = obj.cenaCokolada;
}
double Hrana::tezina()
{
	return (this->brojCokolada*this->tezinaCokolada);
}

Paketic* Hrana::getCopy()
{
	return new Hrana(*this);
}

double Hrana::cena()
{
	return (double)cenaCokolada/tezinaCokolada*brojCokolada;
}

void Hrana::prikaz(ostream& out)
{
	out << "Adresa za isporuku: " << this->adresa << ", boja: " << this->boja << ", broj cokolada: "
		<< brojCokolada << ", tezina cokolada: " << tezina() << ", cena: " << cena();
}

