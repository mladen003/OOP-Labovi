#pragma once
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
	~String();
	inline int duzinaStringa()
	{
		return n;
	}
	int pozicijaPodstringa(const String& podString);
	void ucitavanjeStringa();
	void prikazStringa();
private:
	void alociraj(const char* x);

};

