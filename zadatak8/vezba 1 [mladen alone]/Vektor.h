#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Vektor
{
	int* niz;
	int n;
public:
	Vektor();
	Vektor(int n);
	Vektor(const Vektor& desni);
	~Vektor();
	inline void postavi(int indeks, int vrednost)
	{
		niz[indeks] = vrednost;
	}
	inline int vrednostElementa(int indeks) const
	{
		return niz[indeks];
	}
	void uredjenjeNiza();
	double skalarniProizvod(const Vektor& desni);
	int srVrednost();
	friend ostream& operator<<(ostream& izlaz, const Vektor& obj);
	friend istream& operator>>(istream& ulaz, Vektor& obj);

};

