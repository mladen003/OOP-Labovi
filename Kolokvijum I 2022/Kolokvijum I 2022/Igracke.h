#pragma once
#include "Paketic.h"

class Igracke : public Paketic
{
	int brojAutica;
	double tezinaAutica;
	double cenaAutica;
public:
	Igracke();
	Igracke(int adresa, const char* boja, int brojAutica, double tezinaAutica, double cenaAutica);
	Igracke(const Igracke& obj);
	inline double getTezina()
	{
		return tezinaAutica;
	}
	inline double getCena()
	{
		return cenaAutica;
	}
	double cena();
	void prikaz(ostream& out);
	double tezina();
	Paketic* getCopy();
};

