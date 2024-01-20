#pragma once
#include "Karta.h"
class Nocna : public Karta
{
	int brDanaVazenja;
	int brNociVazenja;
	double osnovica;
public:
	Nocna();
	Nocna(int IDkarte, int redniBrDana, double popust, int brDanaVazenja, int brNociVazenja ,double osnovica);
	Nocna(const Nocna& obj);
	double cenaKarte();
	double zbirniPopust();
	Karta* getCopy();
	inline void setBrDana(int x)
	{
		brDanaVazenja += x;
		brNociVazenja += x;
	}
	void prikaziPodatke(ostream& out);
	inline int getVazenje()
	{
		return brDanaVazenja;
	}

};

