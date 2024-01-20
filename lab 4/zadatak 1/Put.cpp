#include "Put.h"

Put::Put()
{
	alociraj();
}

Put::Put(int n)
{
	alociraj(n);
}

Put::~Put()
{
	dealociraj();
}

Put::Put(const Put& original)
{
	alociraj(original.n, original.niz);
}

Put& Put::operator=(const Put& original)
{
	// a = a
	if (this == &original)
		return *this;

	dealociraj();
	alociraj(original.n, original.niz);
	
	return *this;
}

void Put::postaviElement(int indeks, Element& objekt)
{
	niz[indeks] = objekt.getCopy();
}

void Put::brElemenata()
{
	int zemlja = 0;
	int voda = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i]->getTip() == 1)
			zemlja++;
		else
			voda++;
	}
	cout << "Broj elemenata niz tipa Voda je: " << voda << endl;
	cout << "Broj elemenata niz tipa Zemlja je: " << zemlja << endl;
}

double Put::prosecnaNadmorskaVisina() const
{
	double prosecnaNadmorskaVisina = 0;

	for (int i = 0; i < n; i++)
		if (niz[i] != nullptr)
			prosecnaNadmorskaVisina += niz[i]->vratiVrednost();

	return prosecnaNadmorskaVisina;
}

void Put::alociraj(int n, Element** niz)
{
	this->n = n;

	if (n > 0)
	{
		this->niz = new Element*[n]{};
	}
	else
	{
		this->niz = nullptr;
	}

	if (niz != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			if (niz[i] != nullptr)
			{
				this->niz[i] = niz[i]->getCopy();
			}
		}
	}
}

void Put::dealociraj()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			if (niz[i] != nullptr)
			{
				delete niz[i];
				niz[i] = nullptr;
			}
		}

		delete[]niz;
		niz = nullptr;
	}
}

ostream& operator<<(ostream& out, const Put& objekat)
{
	out << objekat.n << endl;

	if (objekat.niz != nullptr)
	{
		for (int i = 0; i < objekat.n; i++)
		{
			if (objekat.niz[i] != nullptr)
			{
				objekat.niz[i]->stampanje(out);
			}
		}
	}

	return out;
}

istream& operator>>(istream& input, Put& objekat)
{
	int n;
	input >> n;

	objekat.dealociraj();
	objekat.alociraj(n);

	for (int i = 0; i < n; i++) {
		int tip;
		input >> tip;

		if (tip == 1)
		{
			Zemlja element;
			input >> element;
			objekat.postaviElement(i, element);
		}
		else
		{
			Voda element;
			input >> element;
			objekat.postaviElement(i, element);
		}
	}

	return input;
}
