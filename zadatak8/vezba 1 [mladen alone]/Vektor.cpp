#include "Vektor.h"

Vektor::Vektor()
{
	n = 0;
	niz = nullptr;
}

Vektor::Vektor(int n)
{
	this->n = n;
	niz = new Tacka[n];
}

Vektor::Vektor(const Vektor& desni)
{
	n = desni.n;
	niz = nullptr;

	if (desni.niz != nullptr)
	{
		niz = new Tacka[desni.n];
		for (int i = 0; i < n; i++)
			niz[i] = desni.niz[i];
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
			Tacka pom;
			if (niz[i] > niz[j])
			{
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
			else if (niz[i] == niz[j])
				ukloni(j--);
		}
	}
}

double Vektor::skalarniProizvod(const Vektor& desni)
{
	double pr = 0;
	int min = (n < desni.n) ? n : desni.n;
	for (int i = 0; i < min; i++)
	{
		pr += niz[i] % desni.niz[i];
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
		srednjaVrednost += niz[i][2];
	srednjaVrednost /= n;

	double najboljaSrednjaVrednost = fabs(srednjaVrednost - niz[0][2]);
	for (int i = 0; i < n-1; i++)
	{
		if (najboljaSrednjaVrednost > fabs(srednjaVrednost - niz[i][2]))
		{
			ind = i;
			najboljaSrednjaVrednost = fabs(srednjaVrednost - niz[i][2]);
		}
	}

	return ind;
}

Vektor& Vektor::operator=(const Vektor& desni)
{
	if (this == &desni)
		return *this;

	if (this->niz != nullptr)
	{
		delete[]this->niz;
		this->niz = nullptr;
	}

	this->n = desni.n;

	if (desni.niz != nullptr)
	{
		this->niz = new Tacka[this->n];
		for (int i = 0; i < this->n; i++)
		{
			this->niz[i] = desni.niz[i];
		}
	}

	return *this;
}

Vektor Vektor::operator+(const Vektor& desni)
{
	if (n != desni.n)
		return Vektor();

	Vektor k(n);
	for (int i = 0; i < n; i++)
	{
		k.niz[i] = niz[i] + desni.niz[i];
	}
	return k;
}

Vektor Vektor::operator*(const Vektor& desni)
{
	if (n != desni.n)
		return Vektor();

	Vektor k(n);
	for (int i = 0; i < n; i++)
	{
		k.niz[i] = niz[i] * desni.niz[i];
	}
	return k;
}

Vektor Vektor::operator+(double m)
{
	Vektor ret(*this);

	for (int i = 0; i < n; i++)
		ret.niz[i] += m;

	return ret;
}

Vektor Vektor::operator* (double m)
{
	Vektor ret(*this);

	for (int i = 0; i < n; i++)
		ret.niz[i] *= m;

	return ret;
}

void Vektor::rotirajUdesno()
{
	if (n < 1)
		return;

	Tacka pom = niz[n - 1];
	for (int i = n - 1; i > 0; i--)
		niz[i] = niz[i - 1];
	niz[0] = pom;
}

void Vektor::ukloni(int index)
{
	if (n < 1)
		return;

	for (int i = index; i < n - 1; i++)
	{
		niz[i] = niz[i + 1];
	}
	n--;
}

void Vektor::rotirajUlevo()
{
	if (n < 1)
		return;

	Tacka pom = niz[0];
	for (int i = 0; i < n - 1; i++)
	{
		niz[i] = niz[i + 1];
	}
	niz[n - 1] = pom;
}

ostream& operator<<(ostream& izlaz, const Vektor& obj)
{
	izlaz << obj.n << endl;
	if (obj.niz != nullptr) {
		for (int i = 0; i < obj.n; i++)
			izlaz << obj.niz[i] << endl;
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
	obj.niz = new Tacka[obj.n];

	for (int i = 0; i < obj.n; i++)
	{
		ulaz >> obj.niz[i];
	}
	return ulaz;
}
