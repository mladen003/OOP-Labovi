#include "KompleksanBroj.h"
#include "RacionalanBroj.h"
#include <fstream>

int main()
{
	int n = 2018;
	Broj** brojevi = new Broj * [n];

	//srand(time(NULL));

	for (int i = 0; i < n; i += 2) {
		brojevi[i] = new RacionalanBroj(rand() % n + 1, rand() % n + 1);
		brojevi[i + 1] = new KompleksanBroj(rand() % n + 1, rand() % n + 1);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (brojevi[i]->poredjenjeBrojeva(*brojevi[j]) == 1) {
				Broj* pom = brojevi[i];
				brojevi[i] = brojevi[j];
				brojevi[j] = pom;
			}
		}
	}

	fstream f;
	f.open("brojevi.txt", fstream::out);

	for (int i = 0; i < n; i++) {
		brojevi[i]->print(f);
		f << endl;
	}

	f.close();

	if (brojevi != nullptr) {
		for (int i = 0; i < n; i++) {
			if (brojevi[i] != nullptr) {
				delete brojevi[i];
				brojevi[i] = nullptr;
			}
		}
		delete[]brojevi;
		brojevi = nullptr;

	}

	return 0;
}