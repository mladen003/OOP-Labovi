#include "Skup.h"
#include <fstream>
#include <string>
int main()
{
	int n;
	fstream fajl;

	fajl.open("skupovi.txt");
	fajl >> n;
	Skup** skupovi = new Skup * [n];

	for (int i = 0; i < n; i++) {
		skupovi[i] = new Skup();
		fajl >> *(skupovi[i]);
	}
	fajl.close();

	Skup* u = new Skup();
	for (int i = 0; i < n; i++) {
		*u = u->unija(*skupovi[i]);
	}
	cout << *u;

	Skup*  p = new Skup(*skupovi[0]);
	for (int i = 1; i < n; i++) {
		*p = p->presek(*skupovi[i]);
	}
	cout << *p;

	Skup* r = new Skup(*skupovi[0]);
	for (int i = 1; i < n; i++) {
		*r = r->razlika(*skupovi[i]);
	}
	cout << *r;

	if (r)
	{
		delete r;
		r = nullptr;
	}

	if (p)
	{
		delete p;
		p = nullptr;
	}

	if (u)
	{
		delete u;
		u = nullptr;
	}

	for (int i = 0; i < n; i++)
	{ 
		if (skupovi[i])
		{
			delete skupovi[i];
			skupovi[i] = nullptr;
		}
	}
	
	if (skupovi)
	{
		delete[]skupovi;
		skupovi = nullptr;
	}

	return 0;
}