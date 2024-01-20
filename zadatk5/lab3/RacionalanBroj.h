#pragma once
#include "Broj.h"
class RacionalanBroj : public Broj
{
	int a;
	int b;
public:
	RacionalanBroj();
	RacionalanBroj(int a, int b);
	~RacionalanBroj();
	void postaviVrednost();
	void print(ostream& ispis);
};

