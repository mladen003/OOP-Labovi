#include "KompleksanBroj.h"

KompleksanBroj::KompleksanBroj()
	: Broj()
{
	re = 0;
	im = 0;
}

KompleksanBroj::KompleksanBroj(double re, double im)
	: Broj(sqrt(pow(re, 2) + pow(im, 2)), "Kompleksan broj")
{
	this->re = re;
	this->im = im;
}

KompleksanBroj::~KompleksanBroj()
{}

void KompleksanBroj::postaviVrednost()
{
	vrednost = sqrt(pow(re, 2) + pow(im, 2));
}

void KompleksanBroj::print(ostream& ispis)
{
	Broj::print(ispis);

	ispis << " Reprezentacija broja => " << re << (im >= 0 ? " + " : " - ") << fabs(im) << "j";
}

