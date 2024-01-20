#include "Put.h"
#include <fstream>

int main()
{
	fstream f;
	Put* put = new Put(1000);

	f.open("put.txt");
	f >> *put;
	f.close();

	put->brElemenata();
	cout << "Prosecna nadmorska visina na putu iznosi: " << put->prosecnaNadmorskaVisina() << endl;

	Put* kopija = new Put(*put);

	if (put != nullptr)
	{
		delete put;
		put = nullptr;
	}

	kopija->brElemenata();
	cout << "Prosecna nadmorska visina na putu iznosi: " << kopija->prosecnaNadmorskaVisina() << endl;

	if (kopija != nullptr)
	{
		delete kopija;
		kopija = nullptr;
	}

	return 0;
}