#include "Laptop.h"
#include "Torba.h"
#include <fstream>

int main()
{
	fstream f;
	int n = 2018;

	Artikal** artikli = new Artikal * [n];

	for (int i = 0; i < n; i += 2) {
		artikli[i] = new Laptop("Dobra cena!", rand() % 2, rand() % n + 101);
		artikli[i + 1] = new Torba(rand() % n + 101);
	}

	((Torba*)artikli[5])->put(*(artikli[2]));
	((Torba*)artikli[15])->put(*(artikli[6]));
	((Torba*)artikli[25])->put(*(artikli[8]));

	f.open("artikli.txt", fstream::out);
	for (int i = 0; i < n; i++)
	{
		artikli[i]->showDescription(f);
		f << endl;
	}
	f.close();

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (artikli[i]->getPrice() > artikli[j]->getPrice()) {
				Artikal* pom = artikli[i];
				artikli[i] = artikli[j];
				artikli[j] = pom;
			}
		}
	}

	f.open("artikli-sortirani.txt", fstream::out);
	for (int i = 0; i < n; i++)
	{
		artikli[i]->showDescription(f);
		f << endl;
	}
	f.close();

	if (artikli != nullptr) {
		for (int i = 0; i < n; i++) {
			if (artikli[i] != nullptr) {
				delete artikli[i];
				artikli[i] = nullptr;
			}
		}
		delete[] artikli;
		artikli = nullptr;
	}

	Torba* torba = new Torba(29.99);
	{
		Laptop laptop("Lenovo", 1, 399.99);
		torba->put(laptop);
	}
	torba->showDescription(cout);

	if (torba != nullptr)
	{
		delete torba;
		torba = nullptr;
	}

	return 0;
}