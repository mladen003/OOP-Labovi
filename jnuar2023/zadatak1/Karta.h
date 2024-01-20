#pragma once
#include <iostream>
using namespace std;
class Karta
{
protected:
	int IDkarte;
	int redniBrDana;
	double popust;

public:
	Karta();
	Karta(int IDkarte, int redniBrDana, double popust);
	Karta(const Karta& obj);
	virtual ~Karta();
	inline int getID()
	{
		return IDkarte;
	}
	virtual int getVazenje() = 0;
	virtual void setBrDana(int x) = 0;
	virtual Karta* getCopy() = 0;
	virtual double cenaKarte() = 0;
	virtual double zbirniPopust() = 0;
	virtual void prikaziPodatke(ostream& out) = 0;
};

