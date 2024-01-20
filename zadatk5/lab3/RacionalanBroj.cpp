#include "RacionalanBroj.h"

RacionalanBroj::RacionalanBroj()
	: Broj()
{
	a = 0;
	b = 0;
}

RacionalanBroj::RacionalanBroj(int a, int b)
	: Broj((double)a / b, "Racionalan broj")
{
	this->a = a;
	this->b = b;
}

RacionalanBroj::~RacionalanBroj()
{}

void RacionalanBroj::postaviVrednost()
{
	this->vrednost = (double)a / b;
}

void RacionalanBroj::print(ostream& ispis)
{
	Broj::print(ispis);

	ispis << " Reprezentacija broja => " << ((a * b < 0) ? "- " : "") << fabs(a) << "/" << fabs(b);
}