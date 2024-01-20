#include "Niz.h"
#include "ZlatnaPoluga.h"
#include "SefUOblikuKocke.h"
#include <fstream>

int main()
{
	cout << "Sefovi!" << endl;
	try {
		Niz<SefUOblikuKocke> a(5);
		fstream f;
		f.open("niz.txt");
		a.ucitaj(f);
		f.close();
		a.izbaci(2);
		a.ispisi(cout);
		a.izbaci(7);
	}
	catch (const char* error)
	{
		cerr << "Greska pri radu sa nizom: " << error << endl;
	}

	cout << endl << endl << "Poluge!" << endl;
	
	try {
		Niz<ZlatnaPoluga> b(7);
		fstream f;
		f.open("poluga.txt");
		b.ucitaj(f);
		f.close();
		b.izbaci(5);
		b.ispisi(cout);
		b.izbaci(-2);
	}
	catch (const char* error)
	{
		cerr << "Greska pri radu sa nizom: " << error << endl;
	}

	return 0;
}
