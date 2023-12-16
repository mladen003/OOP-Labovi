#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	int trenutniBr;
	int n;
	char* niz;
public:
	String();
	String(int n);
	~String();
	inline int duzinaStringa()
	{
		return n;
	}
	int pozicijaPodstringa(const String& podString);
	void ucitavanjeStringa();
	void prikazStringa();
};

