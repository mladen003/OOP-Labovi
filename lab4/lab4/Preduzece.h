#pragma once
#include "Menager.h"
#include"Developer.h"
class Preduzece
{
	char* naziv;
	int budzet;
	Radnik** niz;
	int maxEl;
	int curr;
	void alociraj(char* naziv, int budzet, Radnik** niz, int maxEl, int curr);
	void dealociraj();
public:
	Preduzece(char* naziv, int maxEl);
	~Preduzece();
	void dodavanjeRadnika(const Radnik& obj, int godina);
	void brisanjeRadnika(int JMBG);
	double isplataRadnicima();
	bool rentabilnost(int budzet);
	Preduzece& operator++();
	Preduzece& operator--();
	friend ostream& operator<<(ostream& out, const Preduzece& obj);
	void sortirajRadnike();
	void ukloni(int index);
};

