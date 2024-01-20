#pragma once
#include "Dnevna.h"
#include"Nocna.h"

class Preduzece
{
	Karta** niz;
	int curr;
	int n;
public:
	Preduzece();
	Preduzece(int n);
	virtual ~Preduzece();
	void dodajKartu(Karta& obj);
	void ukloniKartu(int IDkarte);
	void povecanjeVazenja(int IDkarte, int produzenje);
	void prikazPodataka(ostream& out);
	void vazeceKarte(ostream& out, int datum);
	void najduzeTrajanje(ostream& out);
	void najkraceTrajanje(ostream& out);
	double ukupnaZarada();
};

