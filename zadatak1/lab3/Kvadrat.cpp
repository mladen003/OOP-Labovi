#include "Kvadrat.h"

Kvadrat::Kvadrat()
	: Figura()
{}

Kvadrat::Kvadrat(double a)
	: Figura(1)
{
	this->niz[0] = a;
}

Kvadrat::~Kvadrat()
{}

void Kvadrat::prikazi(ostream& output)
{
	if(n > 0)
		output << niz[0] << ", " << niz[0] << ", " << niz[0] << ", " << niz[0] << "\t P = " << povrsina() << endl;
}

double Kvadrat::povrsina()
{
	return n > 0 ?
		niz[0] * niz[0] :
		Figura::povrsina();
}