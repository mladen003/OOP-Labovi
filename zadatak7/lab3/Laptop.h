#pragma once
#include "Artikal.h"
class Laptop : public Artikal
{
	char* opis;
	int stanje;
public:
	Laptop();
	Laptop(const Laptop& desni);
	Laptop(const char* opis, int stanje, double price);
	~Laptop();
	void showDescription(ostream& ispis);
	inline void turnOn()
	{
		stanje = 1;
		cout << "Laptop je ukljucen" << endl;
	}
	inline void turnOf()
	{
		stanje = 0;
		cout << "Laptop je iskljucen" << endl;
	}

	Artikal* getCopy() const;
};

