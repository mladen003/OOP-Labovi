#include "Zemlja.h"

Zemlja::Zemlja()
	: Element(1)
{
	nadmorskaVisina = 0;
}

Zemlja::Zemlja(int k)
	: Element(1)
{
	nadmorskaVisina = k;
}

double Zemlja::vratiVrednost()
{
	return nadmorskaVisina;
}

void Zemlja::stampanje(ostream& out)
{
	Element::stampanje(out);
	out << " nadmorska visina: " << nadmorskaVisina;
}

Element* Zemlja::getCopy() const
{
	return new Zemlja(*this);
}


istream& operator>>(istream& inp, Zemlja& objekat)
{
	inp >> objekat.nadmorskaVisina;
	return inp;
}

