#include "Pravougaonik.h"

Pravougaonik::Pravougaonik()
	: Figura()
{}

Pravougaonik::Pravougaonik(double a, double b)
	: Figura(2)
{
	this->niz[0] = a;
	this->niz[1] = b;
}

Pravougaonik::~Pravougaonik()
{}

void Pravougaonik::prikazi(ostream& output)
{
	if (n > 2)
		output << niz[0] << ", " << niz[1] << ", " << niz[0] << ", " << niz[1] << "\t P = " << povrsina() << endl;
}

double Pravougaonik::povrsina()
{
	return n > 1 ?
		niz[0] * niz[1] :
		Figura::povrsina();
}
