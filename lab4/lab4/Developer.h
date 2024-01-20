#pragma once
#include "Radnik.h"
class Developer : public Radnik
{
	char* tip;
	int prekovremeniSati;
public:
	Developer();
	Developer(const Developer& obj);
	Developer(char* tip, int prekovremeniSati, int jmbg, int godinaZaposljenja, int brGodina, double osnovica, char* imeIprezime);
	~Developer();
	double plataRadnika();
	void podaciOradniku(ostream& out);
	friend istream& operator>>(istream& in, Radnik& obj);
	Radnik* getCopy() const;
};

