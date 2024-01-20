#pragma once
#include "Artikal.h"
class Torba : public Artikal
{
	Artikal* sadrzaj;
public:
	Torba();
	Torba(double price);
	Torba(const Torba& desni);
	~Torba();
	void showDescription(ostream& ispis);
	void put(Artikal& a);
	void remove();
	Artikal* getCopy() const;
};

