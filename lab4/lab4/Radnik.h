#pragma once
#include <iostream>
using namespace std;
class Radnik
{
protected:
	int jmbg;
	int godinaZaposljenja;
	int brGodina;
	double osnovica;
	char* imeIprezime;
	void alociraj(int jmbg, int godinaZaposljenja, int brGodina, double osnovica, char* imeIprezime);
	void dealociraj();
public:
	Radnik();
	Radnik(int jmbg, int godinaZaposljenja, int brGodina, double osnovica,char* imeIprezime);
	Radnik(const Radnik& obj);
	virtual ~Radnik();
	inline int getJMBG() const
	{
		return jmbg;
	}
	inline const char* getImeIprezime() const
	{
		return imeIprezime;
	}
	inline int getGodinaZaposljenja() const
	{
		return godinaZaposljenja;
	}
	inline void setGodinaZaposljenja(int x)
	{
		godinaZaposljenja = x;
	}

	Radnik& operator++();
	Radnik& operator--();
	int poredjenje(const Radnik& desni);

	virtual double plataRadnika() = 0;
	virtual void podaciOradniku(ostream& out) = 0;
	virtual Radnik* getCopy() const = 0;

	static char* makeCopy(const char* string);
};

