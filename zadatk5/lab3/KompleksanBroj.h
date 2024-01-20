#pragma once
#include "Broj.h"
class KompleksanBroj : public Broj
{
	double re;
	double im;
public:
	KompleksanBroj();
	KompleksanBroj(double re, double im);
	~KompleksanBroj();
	void postaviVrednost();
	void print(ostream& ispis);
};

