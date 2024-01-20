#pragma once
#include <iostream>
using namespace std;

class Broj
{
protected:
	char* vrsta;
	double vrednost;
public:
	Broj();
	Broj(double vrednost, const char* vrsta);
	virtual ~Broj();
	int poredjenjeBrojeva(const Broj& desni);
	virtual void print(ostream& ispis);
	inline virtual double getVrednost()
	{
		return vrednost;
	}
protected:
	virtual void setVrednost(double vrednost)
	{
		this->vrednost = vrednost;
	}
};

