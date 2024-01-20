#pragma once
#include "Karta.h"
class Dnevna : public Karta
{
	int brDanaVazenja;
	double osnovica;
public:
	Dnevna();
	Dnevna(int IDkarte, int redniBrDana, double popust, int brDanaVazenja, double osnovica);
	Dnevna(const Dnevna& obj);
	double cenaKarte();
	double zbirniPopust();
	Karta* getCopy();
	inline void setBrDana(int x)
	{
		brDanaVazenja += x;
	}
	void prikaziPodatke(ostream& out);
	inline int getVazenje()
	{
		return brDanaVazenja;
	}
};

