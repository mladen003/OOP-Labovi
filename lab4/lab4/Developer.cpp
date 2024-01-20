#include "Developer.h"

Developer::Developer()
	: Radnik()
{
	tip = nullptr;
	prekovremeniSati = 0;
}

Developer::Developer(const Developer& obj)
	: Radnik(obj)
{
	int n = 0;
	while (obj.tip[n] != '\0')
		n++;
	this->tip = new char[n + 1];
	for (int i = 0; i < n; i++)
		this->tip[i] = obj.tip[i];
	this->tip[n] = '\0';

	this->prekovremeniSati = obj.prekovremeniSati;
}

Developer::Developer(char* tip, int prekovremeniSati, int jmbg, int godinaZaposljenja, int brGodina, double osnovica, char* imeIprezime)
	: Radnik(jmbg, godinaZaposljenja, brGodina, osnovica, imeIprezime)
{
	this->prekovremeniSati = prekovremeniSati;
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

Developer::~Developer()
{
	if (tip != nullptr) {
		delete[]tip;
		tip = nullptr;
	}
}

double Developer::plataRadnika()
{
	return 25 * osnovica + 1500 * getGodinaZaposljenja() + 1000 * prekovremeniSati;
}

void Developer::podaciOradniku(ostream& out)
{
	out << getImeIprezime() << " ---> " << " Zanimanje: " << tip << ", JMBG: " << getJMBG()
		<< ", Godina zaposljenja: " << getGodinaZaposljenja() << ", Plata: " << plataRadnika();
}

Radnik* Developer::getCopy() const
{
	return new Developer(*this);
}

istream& operator>>(istream& in, Developer& obj)
{
}
