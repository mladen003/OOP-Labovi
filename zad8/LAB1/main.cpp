#include "String.h"

int main()
{
	int n, p;
	char* S;
	cout << "Unesite max duzinu stringa: " << endl;
	cin >> n;
	String stg(n);
	cout << "Unesite podstring koji ce se traziti u glavnom string: " << endl;
	cin >> S;
	cout << "Uneli ste string: " << S << endl;
	stg.UcitavanjeStringa;
	p = stg.PozicijaPodstringa(S);

}