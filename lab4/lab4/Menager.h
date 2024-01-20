#pragma once
#include"Radnik.h"
class Menager : public Radnik
{
	char* tip;
public:
	Menager();
	Menager(const Menager& obj);
	Menager(char* tip, int jmbg, int godinaZaposljenja, int brGodina, double osnovica, char* imeIprezime);
	~Menager();
	double plataRadnika();
	void podaciOradniku(ostream& out);
	friend istream& operator>>(istream& in, Radnik& obj);
	Radnik* getCopy() const;
};

