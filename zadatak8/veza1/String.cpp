#include "String.h"
String::String()
{
	this->n = 0;
	this->niz = nullptr;
}

String::String(int n)
{
	this->n = n;
	this->niz = new char[n];
}

String::String(const char* string)
{
	this->alociraj(string);
}
void String::alociraj(const char* x)
{
	n = 0;
	while (x[n] != '\0')
		n++;

	if (niz != nullptr)
		delete[]niz;

	niz = new char[n + 1];

	for (int i = 0; i <= n; i++)
		niz[i] = x[i];
}
String :: ~String()
{
	if (niz != nullptr)
	{
		delete niz;
		niz = nullptr;
	}
}
int String::pozicijaPodstringa(const String& podString)
{
	for (int i = 0; i <= n - podString.n; i++) {

		int j = 0;
		while (podString.niz[j] == niz[i + j] && j < podString.n) {
			j++;
		}

		if (j == podString.n)
			return i;
	}
	return -1;
}
void String::ucitavanjeStringa()
{
	/* 
	1) Alocirati staticki pomocni niz (buffer)
	2) Ucitam podatke u bafer
	3) Odredim duzinu bafera
	4) Proverim da li mi je niz alocira
	5) ako je alociran dealociram ga (ako to ne uradim imam memory leak)
	6) Alociram novu memoriju za taj niz duzine kao sto je uneseni string
	7) Prekopiram sadrzaj bafera u svoj niz
	*/

	cout << "Unesite zeljeni string: " << endl;

	char unos[200];
	cin >> unos;

	this->alociraj(unos);
}

void String::prikazStringa()
{
	cout << "Ovo je string koji ste uneli: " << endl;

	if(this->niz != nullptr)
		cout << this->niz << endl;

}
