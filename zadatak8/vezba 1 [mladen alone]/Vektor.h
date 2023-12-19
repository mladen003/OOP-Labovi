#pragma once
#include "Tacka.h"

class Vektor
{
	Tacka* niz;
	int n;
public:
	Vektor();
	Vektor(int n);
	Vektor(const Vektor& desni);
	~Vektor();
	inline void postavi(int indeks, Tacka vrednost)
	{
		niz[indeks] = vrednost;
	}
	inline Tacka vrednostElementa(int indeks) const
	{
		return niz[indeks];
	}
	void uredjenjeNiza();
	double skalarniProizvod(const Vektor& desni);
	int srVrednost();
	friend ostream& operator<<(ostream& izlaz, const Vektor& obj);
	friend istream& operator>>(istream& ulaz, Vektor& obj);
	Vektor& operator=(const Vektor& desni);
	Vektor operator+(const Vektor& desni);
	Vektor operator*(const Vektor& desni);
	Vektor operator+(double m);
	Vektor operator*(double m);
	void rotirajUdesno();
	void ukloni(int index);
	void rotirajUlevo();
};

