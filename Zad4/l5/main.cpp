#include "Niz.h"
#include "E3Point.h"
#include <sstream>

int main()
{
	Niz <E3Point> niz(7);

	E3Point a1;
	E3Point a2;
	E3Point a3;
	
	cout << "unesite 0. element niza: " << endl;
	cin >> a1;
	cout << "unesite 1. element niza: " << endl;
	cin >> a2;
	cout << "unesite 2. element niza: " << endl;
	cin >> a3;

	niz.ucitavanjeElemenata(a1);
	niz.ucitavanjeElemenata(a2);
	niz.ucitavanjeElemenata(a3);

	cout << niz;
	
	Niz<E3Point> niz2;

	for (int i = 0; i < 3; i++)
	{
		stringstream ss;
		ss << "Tacka " << i + 1;
		E3Point temp(ss.str().c_str(), (i + 1) * 5, (i + 2) * 6, (i + 3) * 7);
		niz2.ucitavanjeElemenata(temp);
	}

	cout << niz2;

	Niz<E3Point> nizSuma = niz + niz2;

	cout << nizSuma;

	return 0;
}