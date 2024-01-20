#include "Menager.h"

Menager::Menager()
	: Radnik()
{
	tip = nullptr;
}

Menager::Menager(const Menager& obj)
	: Radnik(obj)
{
	int n = 0;
	while (obj.tip[n] != '\0')
		n++;
	this->tip = new char[n + 1];
	for (int i = 0; i < n; i++)
		this->tip[i] = obj.tip[i];
	this->tip[n] = '\0';
}

Menager::Menager(char* tip, int jmbg, int godinaZaposljenja, int brGodina, double osnovica, char* imeIprezime)
	: Radnik(jmbg, godinaZaposljenja, brGodina, osnovica, imeIprezime)
{
	this->tip = nullptr;
	if (tip != nullptr) {
		int n = 0;
		while (tip[n] != '\0')
			n++;

		this->tip = new char[n + 1];
		for (int i = 0; i < n; i++) {
			this->tip[i] = tip[i];
		}
		this->tip[n] = '\0';
	}
}

Menager::~Menager()
{
	if (tip != nullptr) {
		delete[]tip;
		tip = nullptr;
	}
}

double Menager::plataRadnika()
{
	return 30 * osnovica + 1000 * this->getGodinaZaposljenja();
}

void Menager::podaciOradniku(ostream& out)
{
	out << getImeIprezime() << " ---> " << " Zanimanje: " << tip << ", JMBG: " << getJMBG()
		<< ", Godina zaposljenja: " << getGodinaZaposljenja() << ", Plata: " << plataRadnika();
}

Radnik* Menager::getCopy() const
{
	return new Menager(*this);
}
