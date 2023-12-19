#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class String
{
	int n;
	char* niz;

public:
	String();
	String(int n);
	String(const char* string);
	String(const String& s);
	~String();
	inline int duzinaStringa()
	{
		return n;
	}
	int pozicijaPodstringa(const String& podString);
	void ucitavanjeStringa();
	void prikazStringa();

	String nadovezivanje(const String& desni);
	String prvoSlovo();
	String svaVelikaSlova();
	String PadRight(char c, int duzina);
	String& operator=(const String& desni);
	friend ostream& operator<<(ostream& ispis, const String& obj);
	friend istream& operator>>(istream& upis, String& obj);

private:
	void alociraj(const char* x);

};

