#include "Deda.h"

Deda::Deda()
{
	n = 0;
	curr = 0;
	niz = nullptr;
}

Deda::Deda(int n)
{
	curr = 0;
	this->n = n;
	niz = new Paketic * [n];
}

Deda::~Deda()
{
	if (niz != nullptr) {
		for (int i = 0; i < n; i++) {
			if (niz[i] != nullptr) {
				delete niz[i];
				niz[i] = nullptr;
			}
		}
		delete[]niz;
		niz = nullptr;
	}
}

void Deda::dodavanjePaketica(Paketic& obj)
{
	if (niz != nullptr) {
		niz[curr] = obj.getCopy();
		curr++;
	}
}

void Deda::izbacivanjePaketica(int adresa)
{
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++) {
			if (niz[i] != nullptr && niz[i]->getAdresa() == adresa) {
				for (int j = i; j < curr - 1; j++) {
					niz[j] = niz[j + 1];
				}
				curr--;
				
			}
		}
	}
}

void Deda::prikazPaketica(ostream& out)
{
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++) {
			niz[i]->prikaz(out);
			out << endl;
		}
	}
}

double Deda::srednjaCena()
{
	if (niz != nullptr) {
		double s = 0;
		for (int i = 0; i < curr; i++) {
			s += niz[i]->cena();
		}
		return double(s) / curr;
	}
	else
		return -1;
}

void Deda::najteziPaketic(ostream& out)
{
	if (niz != nullptr) {
		double max = -1;
		int index=0;
		for (int i = 0; i < curr; i++) {
			if (niz[i]->tezina() > max) {
				max = niz[i]->tezina();
				index = i;
			}
		}
		niz[index]->prikaz(out);
	}
}
