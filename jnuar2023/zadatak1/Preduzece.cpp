#include "Preduzece.h"

Preduzece::Preduzece()
{
	curr = 0;
	n = 0;
	niz = nullptr;
}

Preduzece::Preduzece(int n)
{
	this->n = n;
	niz = new Karta * [n];
	curr = 0;
}

Preduzece::~Preduzece()
{
	if (niz != nullptr) {
		for (int i = 0; i < n; i++) {
			if (niz[i] != nullptr) {
				delete niz[i];
				niz[i] = nullptr;
			}
		}
		delete[] niz;
		niz = nullptr;
	}
}

void Preduzece::dodajKartu(Karta& obj)
{
	if (curr <= n) {
		niz[curr] = obj.getCopy();
		curr++;
	}
	else
		cout << "Kolekcija je puna!" << endl;
		
}

void Preduzece::ukloniKartu(int IDkarte)
{
	if (niz != nullptr)
	{
		for (int i = 0; i < curr; i++) {
			if (niz[i] != nullptr) {
				if (niz[i]->getID() == IDkarte) {
					//delete niz[i];
					for (int j = i; j < curr-1; j++) {
						niz[j] = niz[j+1];
					}
					delete niz[i];
					niz[i] = nullptr;
					curr--;
					break;
				}
			}
		}
	}
}

void Preduzece::povecanjeVazenja(int IDkarte, int produzenje)
{
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++) {
			if (niz[i] != nullptr) {
				if (niz[i]->getID() == IDkarte) {
					niz[i]->setBrDana(produzenje);
					break;
				}
			}
		}
	}
}

void Preduzece::prikazPodataka(ostream& out) 
{
		if (niz != nullptr) {
			for (int i = 0; i < curr; i++) {
				if (niz[i] != nullptr) 
					niz[i]->prikaziPodatke(out);
			}
		}
}

void Preduzece::vazeceKarte(ostream& out, int datum)
{
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++) {
			if (niz[i] != nullptr) {
				if (datum <= niz[i]->getVazenje())
					niz[i]->prikaziPodatke(out);
			}
		}
	}
}

double Preduzece::ukupnaZarada()
{
	double s = 0;
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++) {
			if (niz[i] != nullptr) {
				s += niz[i]->cenaKarte();
			}
		}
	}
	return s;
}
