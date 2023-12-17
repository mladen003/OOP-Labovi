#include "Vektor.h"

Vektor::Vektor()
{
	n = 0;
	niz = nullptr;
}

Vektor::Vektor(int n)
{
	this->n = n;
	niz = new int[n];
}

Vektor::Vektor(const Vektor& desni)
{
	this->n = desni.n;
	if (niz != nullptr)
		delete[]niz;

	niz = nullptr;
	if (desni.niz != nullptr)
	{
		niz = new int[desni.n];
		for (int i = 0; i < n; i++)
			this->niz[i] = desni.niz[i];
	}
}

Vektor::~Vektor()
{
	if (niz)
	{
		delete[]niz;
		niz = nullptr;
	}
}

void Vektor::uredjenjeNiza()
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = i + 1; j < n; j++)
		{
			int pom;
			if (niz[i] >= niz[j])
			{
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
		}
	}
}

double Vektor::skalarniProizvod(const Vektor& desni)
{
	double pr = 0;
	int min = (n < desni.n) ? n : desni.n;
	for (int i = 0; i < min; i++)
	{
		pr += niz[i] * desni.niz[i];
	}
	return pr;
}


int Vektor::srVrednost()
{
	int ind = -1;

	if (n < 1)
		return ind;

	double srednjaVrednost = 0;
	for (int i = 0; i < n; i++)
		srednjaVrednost += niz[i];
	srednjaVrednost /= n;

	double najboljaSrednjaVrednost = fabs(srednjaVrednost - niz[0]);
	for (int i = 0; i < n-1; i++)
	{
		if (najboljaSrednjaVrednost > fabs(srednjaVrednost - niz[i]))
		{
			ind = i;
			najboljaSrednjaVrednost = fabs(srednjaVrednost - niz[i]);
		}
	}

	return ind;
}

ostream& operator<<(ostream& izlaz, const Vektor& obj)
{
	izlaz << obj.n << endl;
	if (obj.niz != nullptr) {
		for (int i = 0; i < obj.n; i++)
			izlaz << obj.niz[i] << "\t";
	}
	return izlaz;
}

istream& operator>>(istream& ulaz, Vektor& obj)
{
	if (obj.niz != nullptr)
	{
		delete []obj.niz;
		obj.niz = nullptr;
	}
	ulaz >> obj.n;
	obj.niz = new int[obj.n];
	for (int i = 0; i < obj.n; i++)
	{
		ulaz >> obj.niz[i];
	}
	return ulaz;
}
