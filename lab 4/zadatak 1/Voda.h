#pragma once
#include "Element.h"
class Voda : public Element
{
	double dubina;
public:
	Voda();
	Voda(double l);
	friend istream& operator>>(istream& inp, Voda& objekat);
	double vratiVrednost();
	void stampanje(ostream& out);
	Element* getCopy() const;
};

