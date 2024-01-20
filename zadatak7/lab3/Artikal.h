#pragma once
#include <iostream>
using namespace std;
class Artikal
{
protected:
	char* naziv;
	double cena;
public:
	Artikal();
	Artikal(const char* naziv, double cena);
	Artikal(const Artikal& artikal);
	virtual ~Artikal();
	virtual void showDescription(ostream& ispis);
	inline double getPrice()
	{
		return cena;
	}
	virtual Artikal* getCopy() const = 0;
};

