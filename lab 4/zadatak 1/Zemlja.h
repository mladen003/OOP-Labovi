#pragma once
#include"Element.h"

class Zemlja : public Element
{
	int nadmorskaVisina;
public:
	Zemlja();
	Zemlja(int k);
	friend istream& operator>>(istream& inp, Zemlja& objekat);
	double vratiVrednost();
	void stampanje(ostream& out);
	Element* getCopy() const;
};

