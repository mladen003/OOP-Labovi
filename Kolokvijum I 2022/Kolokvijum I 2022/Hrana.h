#pragma once
#include "Paketic.h"

class Hrana : public Paketic
{
	int brojCokolada;
	double tezinaCokolada;
	double cenaCokolada;
public:
	Hrana();
	Hrana(int adresa, const char* boja, int brojCokolada, double tezinaCokolada, double cenaCokolada);
	Hrana(const Hrana& obj);
	double getTezina() {
		return tezinaCokolada;
	}
	double getCena()
	{
		return cenaCokolada;
	}
	double cena();
	void prikaz(ostream& out);
	double tezina();
	Paketic* getCopy();
};

