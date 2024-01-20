#include "Figura.h"

Figura::Figura()
{
	this->n = 0;
	this->niz = nullptr;
}

Figura::Figura(int n)
{
	this->n = n;
	this->niz = new double[n];
}

Figura::~Figura()
{
	if (niz != nullptr)
	{
		delete[]niz;
		niz = nullptr;
	}
}

double Figura::povrsina()
{
	throw new exception("Nije definisana povrsina!");
}

void Figura::prikazi(ostream& output)
{
	output << n << endl;

	for (int i = 0; i < n; i++)
		output << niz[i] << ", ";
	output << endl;
}

