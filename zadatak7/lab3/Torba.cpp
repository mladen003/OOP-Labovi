#include "Torba.h"

Torba::Torba()
	: Artikal()
{
	sadrzaj = nullptr;
}

Torba::Torba(const Torba& desni)
	: Artikal(desni)
{
	if (desni.sadrzaj != nullptr)
		this->sadrzaj = desni.sadrzaj->getCopy();
}

Torba::Torba(double price)
	: Artikal("Torba za laptop", price)
{
	sadrzaj = nullptr;
}

Torba::~Torba()
{}

void Torba::showDescription(ostream& ispis)
{
	Artikal::showDescription(ispis);

	ispis << " sadrzaj: ";
	if (sadrzaj != nullptr)
	{
		sadrzaj->showDescription(ispis);
	}
	else {
		ispis << "prazna!";
	}
}

void Torba::put(Artikal& a)
{
	if (sadrzaj == nullptr) {
		this->sadrzaj = a.getCopy();
		cout << "Artikal je smesten u torbu" << endl;
	}
	else {
		cout << "Torba vec sadrzi artikal" << endl;
	}
}

void Torba::remove()
{
	if (sadrzaj != nullptr) {
		delete sadrzaj;
		sadrzaj = nullptr;
		cout << "Torba je sada prazna" << endl;
	}
	else {
		cout << "Torba je vec prazna" << endl;
	}
}

Artikal* Torba::getCopy() const
{
	return new Torba(*this);
}
