#pragma once

template <typename T, int k>
class Niz
{
	T elementi[k];
	int curr;
public:
	Niz();
	int brElemenata()
	{
		return curr;
	}
	void ucitavanjeElemenata(istream& input);
	void prikazNiza(ostream& out);
	void uredjivanjeNiza();
	T& operator[](int n);
};

template<typename T, int k>
inline Niz<T, k>::Niz()
{
	curr = 0;
}

template<typename T, int k>
inline void Niz<T, k>::ucitavanjeElemenata(istream& input)
{
	int korisnikN = 0;
	input >> korisnikN;

	if (k < korisnikN)
		throw "Maksimalan broj elemenata za unos je premasen!";

	curr = min(k, korisnikN);
	for (int i = 0; i < curr; i++)
		input >> elementi[i];
}

template<typename T, int k>
inline void Niz<T, k>::prikazNiza(ostream& out)
{
	for (int i = 0; i < curr; i++)
		out << i + 1 << ". element" << endl << elementi[i] << endl;
}

template<typename T, int k>
inline void Niz<T, k>::uredjivanjeNiza()
{
	T pom;
	for (int i = 0; i < curr - 1; i++) {
		for (int j = i + 1; j < curr; j++) {
			if (elementi[i] < elementi[j]) {
				pom = elementi[i];
				elementi[i] = elementi[j];
				elementi[j] = pom;
			}
		}
	}
}

template<typename T, int k>
inline T& Niz<T, k>::operator[](int n)
{
	if (n > curr)
		throw "Index je van opsega";

	return elementi[n];
}
