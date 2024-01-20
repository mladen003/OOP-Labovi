#include "Deda.h"
#include <fstream>
int main()
{
	fstream f;
	Deda* deda = new Deda(6);
	Paketic* p1 = new Hrana(71, "crvena", 5, 14.3, 50.5);
	Paketic* p2 = new Igracke(72, "plava", 8, 12, 71.6);
	Paketic* p3 = new Hrana(73, "zuta", 23, 14.3, 18.5);
	Paketic* p4 = new Igracke(74, "ljubicasta", 3, 12, 100.6);
	Paketic* p5 = new Hrana(75, "braon", 18, 14.3, 42.5);
	Paketic* p6 = new Igracke(76, "zelena", 34, 12, 51.6);

	deda->dodavanjePaketica(*p1);
	deda->dodavanjePaketica(*p2);
	deda->dodavanjePaketica(*p3);
	deda->dodavanjePaketica(*p4);
	deda->dodavanjePaketica(*p5);
	deda->dodavanjePaketica(*p6);

	f.open("pokloni.txt", fstream::out);
	deda->izbacivanjePaketica(73);
	deda->prikazPaketica(f);
	f.close();

	cout << deda->srednjaCena() << endl;
	deda->najteziPaketic(cout);

	if (p6 != nullptr) {
		delete p6;
		p6 = nullptr;
	}
	if (p5 != nullptr) {
		delete p5;
		p5 = nullptr;
	}
	if (p4 != nullptr) {
		delete p4;
		p4 = nullptr;
	}
	if (p3 != nullptr) {
		delete p3;
		p3 = nullptr;
	}
	if (p2 != nullptr) {
		delete p2;
		p2 = nullptr;
	}
	if (p1 != nullptr) {
		delete p1;
		p1 = nullptr;
	}

	return 0;
}