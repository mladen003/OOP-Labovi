#include "Vektor.h"

int main()
{
	fstream f;

	int m;

	f.open("koordinate.txt");
	f >> m;

	Vektor** viktorovi = new Vektor*[m];
	for (int i = 0; i < m; i++) {
		viktorovi[i] = new Vektor();
		f >> *(viktorovi[i]);
	}

	f.close();

	Vektor* uredjenVektor = new Vektor(*(viktorovi[0]));
	uredjenVektor->uredjenjeNiza();

	f.open("uredjen vektor.txt", fstream::out);
	f << *uredjenVektor << endl;
	f.close();

	uredjenVektor->rotirajUlevo();
	f.open("rotiran vektor ulevo.txt", fstream::out);
	f << *uredjenVektor << endl;
	f.close();

	uredjenVektor->rotirajUdesno();
	uredjenVektor->rotirajUdesno();
	f.open("rotiran vektor udesno.txt", fstream::out);
	f << *uredjenVektor << endl;
	f.close();

	cout << *uredjenVektor;
	cout << "[" << uredjenVektor->srVrednost() <<"] " << uredjenVektor->vrednostElementa(uredjenVektor->srVrednost()) << endl;

	delete uredjenVektor;

	Vektor* zbirVektora = new Vektor(*(viktorovi[0]));
	for (int i = 1; i < m; i++)
		*zbirVektora = *zbirVektora + *(viktorovi[i]);

	f.open("zbir vektora.txt", fstream::out);
	f << *zbirVektora << endl;
	f.close();

	Vektor* mnozenjeVektora = new Vektor(*(viktorovi[0]));
	for (int i = 1; i < m; i++)
		*mnozenjeVektora = *mnozenjeVektora * *(viktorovi[i]);

	f.open("mnozenje vektora.txt", fstream::out);
	f << *mnozenjeVektora << endl;
	f.close();
	
	double skalar;

	cout << "Unesite skalar kojim sabiramo elemente vektora: ";
	cin >> skalar;

	Vektor** zbirSkalarom = new Vektor*[m];
	for (int i = 0; i < m; i++)
		zbirSkalarom[i] = new Vektor(*(viktorovi[i]) + skalar);

	f.open("zbir vektora skalarom.txt", fstream::out);
	f << m << endl;
	for (int i = 0; i < m; i++)
		f << *(zbirSkalarom[i]) << endl;
	f.close();

	cout << "Unesite skalar kojim mnozimo elemente vektora: ";
	cin >> skalar;
	Vektor** mnozenjeSkalarom = new Vektor*[m];
	for (int i = 0; i < m; i++)
		mnozenjeSkalarom[i] = new Vektor(*(viktorovi[i]) * skalar);

	f.open("mnozenje vektora skalarom.txt", fstream::out);
	f << m << endl;
	for (int i = 0; i < m; i++)
		f << *(mnozenjeSkalarom[i]) << endl;
	f.close();

	// destruktori

	if (mnozenjeSkalarom != nullptr)
	{
		for (int i = 0; i < m; i++)
		{
			if (mnozenjeSkalarom[i] != nullptr)
			{
				delete mnozenjeSkalarom[i];
				mnozenjeSkalarom[i] = nullptr;
			}
		}
		delete []mnozenjeSkalarom;
		mnozenjeSkalarom = nullptr;
	}

	if (zbirSkalarom != nullptr)
	{
		for (int i = 0; i < m; i++)
		{
			if (zbirSkalarom[i] != nullptr)
			{
				delete zbirSkalarom[i];
				zbirSkalarom[i] = nullptr;
			}
		}
		delete[]zbirSkalarom;
		zbirSkalarom = nullptr;
	}

	if (mnozenjeVektora != nullptr) {
		delete mnozenjeVektora;
		mnozenjeVektora = nullptr;
	}

	if (zbirVektora != nullptr) {
		delete zbirVektora;
		zbirVektora = nullptr;
	}

	if (viktorovi != nullptr) {
		for (int i = 0; i < m; i++) {
			if (viktorovi[i] != nullptr) {
				delete viktorovi[i];
				viktorovi[i] = nullptr;
			}
		}
		delete[]viktorovi;
		viktorovi = nullptr;
	}

	return 0;
}