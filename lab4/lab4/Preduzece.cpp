#include "Preduzece.h"

void Preduzece::alociraj(char* naziv, int budzet, Radnik** niz, int maxEl, int curr)
{
	this->budzet = budzet;
	this->maxEl = maxEl;
	this->curr = curr;
	this->naziv = Radnik::makeCopy(naziv);
	this->niz = new Radnik * [maxEl] {};

	if (niz != nullptr)
		for (int i = 0; i < curr; i++)
			this->niz[i] = niz[i]->getCopy();
}

void Preduzece::dealociraj()
{
	if (naziv != nullptr) {
		delete[] naziv;
		naziv = nullptr;
	}

	if (niz != nullptr) {
		for (int i = 0; i < maxEl; i++) {
			if (niz[i] != nullptr) {
				delete niz[i];
				niz[i] = nullptr;
			}
		}
		delete[] niz;
		niz = nullptr;
	}
}

Preduzece::Preduzece(char* naziv, int maxEl)
{
	alociraj(naziv, 0, nullptr, maxEl, 0);
}

Preduzece::~Preduzece()
{
	dealociraj();
}

void Preduzece::dodavanjeRadnika(const Radnik& obj, int godina)
{
	if (maxEl == curr) {
		int newmaxEl = maxEl > 0 ? maxEl * 2 : 1;
		Radnik** oldNiz = niz;
		niz = new Radnik * [newmaxEl] {};
		for (int i = 0; i < maxEl; i++) {
			niz[i] = oldNiz[i];
		}
		maxEl = newmaxEl;

		if (oldNiz != nullptr) {
			delete[] oldNiz;
			oldNiz = nullptr;
		}
	}

	niz[curr] = obj.getCopy();
	niz[curr++]->setGodinaZaposljenja(godina);
}

void Preduzece::brisanjeRadnika(int JMBG)
{
	for (int i = 0; i < curr; i++)
	{
		if (niz[i] != nullptr && niz[i]->getJMBG() == JMBG)
		{
			ukloni(i);
			return;
		}
	}
}

double Preduzece::isplataRadnicima()
{
	if (niz != nullptr) {
		double suma = 0;
		for (int i = 0; i < curr; i++) {
			suma+=niz[i]->plataRadnika();
		}
		return suma;
	}
}

bool Preduzece::rentabilnost(int budzet)
{
	if (budzet - isplataRadnicima() > 0)
		return true;
	else
		return false;
}

Preduzece& Preduzece::operator++()
{
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++) {
			++(*(niz[i]));
		}
	}
}

Preduzece& Preduzece::operator--()
{
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++) {
			--(*(niz[i]));
		}
	}
}

void Preduzece::sortirajRadnike()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < curr - 1; i++)
		{
			for (int j = i + 1; j < curr; j++)
			{
				if (
					niz[i] != nullptr &&
					niz[j] != nullptr &&
					niz[i]->getGodinaZaposljenja() > niz[j]->getGodinaZaposljenja()
					)
				{
					Radnik* pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}
			}
		}
	}
}

void Preduzece::ukloni(int index)
{
	if (index >= curr)
		return;

	Radnik* radnik = niz[index];

	for (int i = index; i < curr - 1; i++)
		niz[i] = niz[i + 1];

	curr--;

	if (radnik != nullptr)
		delete radnik;
}

ostream& operator<<(ostream& out, const Preduzece& obj)
{
	if (obj.niz != nullptr)
	{
		for (int i = 0; i < obj.curr; i++)
			if (obj.niz[i] != nullptr)
				obj.niz[i]->podaciOradniku(out);
	}

	return out;
}
