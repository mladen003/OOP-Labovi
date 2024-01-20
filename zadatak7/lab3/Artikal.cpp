#include "Artikal.h"

Artikal::Artikal()
{
	cena = 0;
	naziv = nullptr;
}

Artikal::Artikal(const char* naziv, double cena)
{
	this->cena = cena;

	int n = 0;
	while (naziv[n] != '\0')
		n++;

	this->naziv = new char[n + 1];

	for(int i=0;i<n;i++)
		this->naziv[i] = naziv[i];
	this->naziv[n] = '\0';
}

Artikal::Artikal(const Artikal& artikal)
{
	this->cena = artikal.cena;
	
	if (artikal.naziv != nullptr) {

		int n = 0;
		while (artikal.naziv[n] != '\0')
			n++;

		this->naziv = new char[n + 1];

		for (int i = 0; i < n; i++)
			this->naziv[i] = artikal.naziv[i];
		this->naziv[n] = '\0';
	}
	else
		this->naziv = nullptr;
}

Artikal::~Artikal()
{
	if (naziv != nullptr)
	{
		delete [] naziv;
		naziv = nullptr;
	}
}

void Artikal::showDescription(ostream& ispis)
{
	ispis << naziv << " ---> " << "cena: " << cena;
}
