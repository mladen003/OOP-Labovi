#include "Laptop.h"

Laptop::Laptop()
	: Artikal()
{
	stanje = 0;
	opis = nullptr;
}

Laptop::Laptop(const Laptop& desni)
	: Artikal(desni)
{
	this->stanje = desni.stanje;

	if (desni.opis != nullptr) {

		int n = 0;
		while (desni.opis[n] != '\0')
			n++;

		this->opis = new char[n + 1];

		for (int i = 0; i < n; i++)
			this->opis[i] = desni.opis[i];
		this->opis[n] = '\0';
	}
	else
		this->opis = nullptr;
}

Laptop::Laptop(const char* opis, int stanje, double price)
	: Artikal("Laptop", price)
{
	this->stanje = stanje;

	int n = 0;
	while (opis[n] != '\0')
		n++;

	this->opis = new char[n + 1];

	for (int i = 0; i < n; i++)
		this->opis[i] = opis[i];
	this->opis[n] = '\0';
}

Laptop::~Laptop()
{
	if (opis != nullptr)
	{
		delete[] opis;
		opis = nullptr;
	}
}

void Laptop::showDescription(ostream& ispis)
{
	Artikal::showDescription(ispis);
	ispis << " opis: " << opis << " stanje: " << stanje;
}

Artikal* Laptop::getCopy() const
{
	return new Laptop(*this);
}
