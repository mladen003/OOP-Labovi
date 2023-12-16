#include "String.h"
int main()
{
	int n = 10;
	String* str = new String(n);
	str->ucitavanjeStringa();

	cout << "Unesite podstring koji ce se traziti u glavnom stringu: " << endl;
	String podstring = 20;
	podstring.ucitavanjeStringa();

	int p = str->pozicijaPodstringa(podstring);
	if (p == -1)
		cout << "Glavni string ne sadrzi podstring." << endl;
	else
		cout << "Pozicija podstringa je: " << p+1 << endl;

	p = str->pozicijaPodstringa("ana");

	if (str != nullptr)
	{
		delete str;
		str = nullptr;
	}

	return 0;
}