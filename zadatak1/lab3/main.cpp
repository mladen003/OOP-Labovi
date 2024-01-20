#include "Kvadrat.h"
#include "Pravougaonik.h"

#include <random>
#include <fstream>

int main()
{
	int n = 2018;
	Figura** figure = new Figura * [n];

	for (int i = 0; i < n; i += 2)
	{
		figure[i] = new Kvadrat(rand() % n + 1);
		figure[i + 1] = new Pravougaonik(rand() % n + 1, rand() % n + 1);
	}

	cout << n << endl;
	for (int i = 0; i < n; i++)
		figure[i]->prikazi(cout);

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (figure[i]->povrsina() > figure[j]->povrsina())
			{
				Figura* pom = figure[i];
				figure[i] = figure[j];
				figure[j] = pom;
			}
		}
	}

	fstream* file = new fstream();

	file->open("Figure.txt", fstream::out);

	*file << n << endl;
	for (int i = 0; i < n; i++)
		figure[i]->prikazi(*file);

	file->close();

	if (file != nullptr)
	{
		delete file;
		file = nullptr;
	}

	if (figure != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			if (figure[i] != nullptr)
			{
				delete figure[i];
				figure[i] = nullptr;
			}
		}

		delete[] figure;
		figure = nullptr;
	}

	try
	{
		Figura* f = new Kvadrat();
		f->povrsina();
	}
	catch (exception* greska)
	{
		cerr << greska->what() << endl;
	}

	return 0;
}