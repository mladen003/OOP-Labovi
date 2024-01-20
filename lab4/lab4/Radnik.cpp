#include "Radnik.h"

Radnik::Radnik(int jmbg, int godinaZaposljenja, int brGodina, double osnovica, char* imeIprezime)
{
	alociraj(jmbg, godinaZaposljenja, brGodina, osnovica, imeIprezime);
}

void Radnik::alociraj(int jmbg, int godinaZaposljenja, int brGodina, double osnovica, char* imeIprezime)
{
	this->jmbg = jmbg;
	this->godinaZaposljenja = godinaZaposljenja;
	this->brGodina = brGodina;
	this->osnovica = osnovica;
	this->imeIprezime = makeCopy(imeIprezime);
}

void Radnik::dealociraj()
{
	if (imeIprezime != nullptr) {
		delete[]imeIprezime;
		imeIprezime = nullptr;
	}
}

Radnik::Radnik()
{
	jmbg = 0;
	godinaZaposljenja = 0;
	brGodina = 0;
	osnovica = 0;
	imeIprezime = nullptr;
}

Radnik::Radnik(const Radnik& obj)
{
	this->jmbg = obj.jmbg;
	this->godinaZaposljenja = obj.godinaZaposljenja;
	this->brGodina = obj.brGodina;
	this->osnovica = obj.osnovica;
	this->imeIprezime = nullptr;

	if (obj.imeIprezime != nullptr)
	{
		int n = 0;
		while (obj.imeIprezime[n] != '\0')
			n++;
		this->imeIprezime = new char[n + 1];
		for (int i = 0; i < n; i++)
			this->imeIprezime[i] = obj.imeIprezime[i];
		this->imeIprezime[n] = '\0';
	}
}

Radnik::~Radnik()
{
	dealociraj();
}

Radnik& Radnik::operator++()
{
	osnovica = osnovica + (double)osnovica / 10;
	return *this;
}

Radnik& Radnik::operator--()
{
	osnovica = osnovica - (double)osnovica / 10;
	return *this;
}

int Radnik::poredjenje(const Radnik& desni)
{
	if (this->brGodina > desni.brGodina)
		return 1;
	else if (this->brGodina == desni.brGodina)
		return 0;
	else 
		return -1;
}

char* Radnik::makeCopy(const char* string)
{
	if(string==nullptr)
		return nullptr;

	char* kopija;
	int n = 0;
	while (string[n] != '\0')
		n++;

	kopija = new char[n + 1];
	for (int i = 0; i < n; i++) {
		kopija[i] = string[i];
	}
	kopija = '\0';

	return kopija;
}





