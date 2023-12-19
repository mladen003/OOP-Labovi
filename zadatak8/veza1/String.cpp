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
String::String(const String& s)
{
	n = s.n;

	niz = new char[n+1];
	for (int i = 0; i < n; i++)
		niz[i] = s.niz[i];
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

String String::nadovezivanje(const String& desni)
{
	n = 0;
	while (niz[n] != '\0')
		n++;
	
	int m = 0;
	while (desni.niz[m] != '\0')
		m++;

	String s(n+m);

	for (int i = 0; i < n; i++)
		s.niz[i] = this->niz[i];

	for (int j = 0; j < m; j++)
		s.niz[n + j] = desni.niz[j];

	s.niz[n + m] = '\0';

	return s;
}

String String::prvoSlovo()
{
	if (n < 1)
		return *this;

	String s(*this);
	for (int i = 0; i < n; i++) {
		if (s.niz[i] >= 'a' && s.niz[i] <= 'z') {
			s.niz[i] = s.niz[i] - ('a' - 'A');
			return s;
		}
		else if (s.niz[i] >= 'A' && s.niz[i] <= 'Z')
			return s;
	}
	return *this;
}

String String::svaVelikaSlova()
{
	if (n < 1)
		return *this;

	String s(*this);

	for (int i = 0; i < n; i++) {
		if(s.niz[i] >= 'a' && s.niz[i]<= 'z')
			s.niz[i] = s.niz[i] - ('a' - 'A');
	}

	return s;
}

String String::PadRight(char c, int duzina)
{
	String s(duzina);

	int n = 0;
	while (niz[n] != '\0')
		n++;

	for (int i = 0; i < n; i++)
		s.niz[i] = niz[i];

	for (int j = n; j < duzina; j++)
		s.niz[j] = c;
	s.niz[duzina] = '\0';

	return s;
}

String& String::operator=(const String& desni)
{
	if (this == &desni)
		return *this;

	if (niz != nullptr) {
		delete []niz;
		niz = nullptr;
	}

	n = desni.n;
	 
	niz = new char[desni.n + 1];

	for (int i = 0; i < desni.n; i++)
		niz[i] = desni.niz[i];

	niz[desni.n] = '\0';

	return *this;
}

ostream& operator<<(ostream& ispis, const String& obj)
{
	ispis << obj.n << endl;
	if (obj.niz != nullptr) {
		for (int i = 0; i < obj.n; i++)
			ispis << obj.niz[i];
	}
	return ispis;
}

istream& operator>>(istream& upis, String& obj)
{
	upis >> obj.n;
	if (obj.niz != nullptr) {
		delete[]obj.niz;
		obj.niz = nullptr;
	}

	obj.niz = new char[obj.n+1];

	for (int i = 0; i < obj.n; i++)
		upis >> obj.niz[i];
	obj.niz[obj.n] = '\0';

	return upis;
}
