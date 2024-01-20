#include "Preduzece.h"

int main()
{
	Preduzece* preduzece = new Preduzece(6);
	Karta* k1 = new Dnevna(178658, 3, 10, 17, 1200);
	Karta* k2 = new Nocna(178657, 2, 13, 20, 21, 1500);
	Karta* k3 = new Dnevna(178656, 4, 30, 17, 1200);
	Karta* k4 = new Nocna(178655, 7, 11, 20, 21, 1500);
	Karta* k5 = new Dnevna(178654, 1, 50, 17, 1200);
	Karta* k6 = new Nocna(178653, 5, 75, 20, 21, 1500);

	preduzece->dodajKartu(*k1);
	preduzece->dodajKartu(*k2);
	preduzece->dodajKartu(*k3);
	preduzece->dodajKartu(*k4);
	preduzece->dodajKartu(*k5);
	preduzece->dodajKartu(*k6);

	preduzece->vazeceKarte(cout, 18);

	return 0;
}