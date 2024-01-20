#pragma once
#include "Hrana.h"
#include "Igracke.h"

class Deda
{
	Paketic** niz;
	int n;
	int curr;
public:
	Deda();
	Deda(int n);
	~Deda();
	void dodavanjePaketica(Paketic& obj);
	void izbacivanjePaketica(int adresa);
	void prikazPaketica(ostream& out);
	double srednjaCena();
	void najteziPaketic(ostream& out);
};

