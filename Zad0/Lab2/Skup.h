#pragma once
#include "Complex.h"
class Skup
{
	int n;
	Complex* niz;
	int curr;
public:
	Skup();
	Skup(const Skup& a);
	Skup(int n);
	~Skup();
	inline int brElemenata() {
		return n;
	}
	void izbacivanjeDuplikata();
	void uredjeneNiza();
	int pripadnostElementa(const Complex& el);
	void ucitavanjeElemenata();
	void ispisElemenata();
	Complex izbaci(int index);
	void ubaci(const Complex& a);
	void dupliraj();

	Skup razlika(const Skup& a) const;
	Skup presek(const Skup& a);
	Skup unija(const Skup& a);
	Skup& operator=(const Skup& desni);
	friend ostream& operator<<(ostream& ispis, const Skup& objekat);
	friend istream& operator>>(istream& upis, Skup& objekat);
	
};

