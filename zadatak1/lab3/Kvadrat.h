#pragma once
#include "Figura.h"

class Kvadrat : public Figura
{
public:
	Kvadrat();
	Kvadrat(double a);
	virtual ~Kvadrat();
	void prikazi(ostream& output);
	double povrsina();
};

