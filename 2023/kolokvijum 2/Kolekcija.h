#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Kolekcija
{
	T* niz;
	int n;
	int curr;
	void dealociraj();
public:
	Kolekcija(int n);
	~Kolekcija();
	void DodajPodatak(const T& k);
	void Obrisi(int k);
	float OdrediProsek();
	T NajveciPodatak();
	void Sacuvaj(const char* putanja);
	void Ucitaj(const char* putanja);

	template<class T>
	friend ostream& operator<<(ostream& output, const Kolekcija<T>& obj);
};

template<class T>
inline void Kolekcija<T>::dealociraj()
{
	if (this->niz != nullptr) {
		delete[]this->niz;
		this->niz = nullptr;
	}
}

template<class T>
inline Kolekcija<T>::Kolekcija(int n)
{
	this->n = n;
	niz = new T[n];
	curr = 0;
}

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	dealociraj();
}

template<class T>
inline void Kolekcija<T>::DodajPodatak(const T& k)
{
	if (curr >= n)
		throw "Kolekcija je puna!";

	niz[curr++] = k;
}

template<class T>
inline void Kolekcija<T>::Obrisi(int k)
{
	if (k >= curr)
		throw "Element sa prosledjenim indeksom ne postoji!";

	for (int i = k; i < curr - 1; i++) {
		niz[i] = niz[i + 1];
	}

	curr--;
}

template<class T>
inline float Kolekcija<T>::OdrediProsek()
{
	if (curr < 0)
		return 0;

	float suma = 0;
	for (int i = 0; i < curr; i++)
		suma += niz[i];

	return suma / (float)curr;
}

template<class T>
inline T Kolekcija<T>::NajveciPodatak()
{
	if (curr == 0)
		throw "Nema podataka u kolekciji!";

	T maksimalni = niz[0];
	for (int i = 1; i < curr; i++) {
		if (niz[i] > maksimalni)
			maksimalni = niz[i];
	}

	return maksimalni;
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* putanja)
{
	try {
		ofstream f;
		f.open(putanja);
		f << n << " " << curr << endl;
		for (int i = 0; i < curr; i++) {
			f << niz[i] << endl;
		}
		f.close();
	}
	catch (const ofstream::failure& e)
	{
		throw e.what();
	}
}

template<class T>
inline void Kolekcija<T>::Ucitaj(const char* putanja)
{
	try {
		ifstream f;
		f.open(putanja);

		f >> n >> curr;

		dealociraj();

		niz = new T[n];
		for (int i = 0; i < curr; i++) {
			f >> niz[i];
		}

		f.close();
	}
	catch (const ifstream::failure& e)
	{
		throw e.what();
	}
}

template<class T>
inline ostream& operator<<(ostream& output, const Kolekcija<T>& obj)
{
	output << obj.n << " " << obj.curr << endl;

	for (int i = 0; i < obj.curr; i++)
	{
		output << obj.niz[i] << endl;
	}

	return output;
}
