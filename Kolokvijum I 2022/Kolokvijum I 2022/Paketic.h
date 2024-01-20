#pragma once
#include <iostream>
using namespace std;

class Paketic
{
protected:
	int adresa;
	char* boja;
public:
	Paketic();
	Paketic(int adresa, const char* boja);
	virtual ~Paketic();
	virtual double cena() = 0;
	inline int getAdresa()
	{
		return adresa;
	}
	virtual void prikaz(ostream& out) = 0;
	virtual double tezina() = 0;
	virtual Paketic* getCopy() = 0;
};

