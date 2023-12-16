#include "String.h"

String::String()
{
	this->trenutniBr = 0;
	this->n = 0;
	this->niz = nullptr;
}
String::String(int n)
{
	niz = new char[10];

}
int String::pozicijaPodstringa(const String& podString)
{
	int m = 0;
	while (podString[m] != '\0')
		m++;
	for (int i = 0; i < this->n - m; i++) {
		int j;
		for (j = 0; j < m; j++) {
			if (niz[i + j] != S[j])
				break;
		}

		if (j == m)
			return i;

	}
	return -1;
}
void String::ucitavanjeStringa()
{
	cout << "Unesite zeljeni string: " << endl;
	cin >> this->niz;
}
void String::prikazStringa()
{
	cout << "Ovo je uneti string: " << endl;
	cout << this->niz;
}
String::~String() {}