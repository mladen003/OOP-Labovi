#pragma once
#include <iostream>
using namespace std;

template <class T>
class Niz
{
	T* niz;
	int n;
	int curr;
public:
	Niz();
	Niz(int n);
	~Niz();
	void izbaci(int k);
	void ubaci(const T& obj);
	void ucitaj(istream& input);
	void ispisi(ostream& output);
	void sortiraj();
private:
	void dealociraj();
	T sumaElemenata() const;
};

template<class T>
inline Niz<T>::Niz()
{
	n = 0;
	curr = 0;
	niz = nullptr;
}

template<class T>
inline Niz<T>::Niz(int n)
{
	this->n = n;
	curr = 0;
	niz = new T[n];
}

template<class T>
inline Niz<T>::~Niz()
{
	dealociraj();
}

template<class T>
inline void Niz<T>::izbaci(int k)
{
	if (niz == nullptr)
		throw "Niz je prazan!";
	else if (k >= curr || k < 0)
		throw "Prosledjeni indeks je van opsega!";
	for (int i = k; i < curr - 1; i++) {
		niz[i] = niz[i + 1]; // operator dodele za klase
	}
	curr--;

}

template<class T>
inline void Niz<T>::ubaci(const T& obj)
{
	if (curr == n)
		throw "Niz je pun!";

	if (sumaElemenata() > obj)
		throw "Element ne moze biti ubacen jer ne zadovoljava uslov superrastuceg niza!";

	niz[curr++] = obj;  // operator dodele za klase
}

template<class T>
inline void Niz<T>::ucitaj(istream& input)
{
	dealociraj();

	input >> n;
	input >> curr;
	T pom;
	niz = new T[n]; // default constructor za T
	for (int i = 0; i < curr; i++) {
		input >> niz[i]; // operator>>
	}

	sortiraj();
}

template<class T>
inline void Niz<T>::ispisi(ostream& output)
{
	output << n << " " << curr << endl;
	for (int i = 0; i < curr; i++)
		output << niz[i] << endl; // operator<<
}

template<class T>
inline void Niz<T>::sortiraj()
{
	T suma = 0; // Constructor sa jednim int parametrom koji se ponasa kao default za sabiranje
	for (int i = 0; i < curr - 1; i++)
	{
		int iMin = i;
		for (int j = i + 1; j < curr; j++)
		{
			if (niz[iMin] > niz[j])
			{
				iMin = j;
			}
		}

		if (iMin != i)
		{
			T pom = niz[i]; // Copy constructor
			niz[i] = niz[iMin]; // Dodela
			niz[iMin] = pom; // Dodela
		}

		if (suma > niz[i]) // operator>
		{
			throw "Niz ne moze biti sortiran u superrastuci!";
		}
		else
		{
			suma += niz[i]; // operator +=
		}
	}
}

template<class T>
inline void Niz<T>::dealociraj()
{
	if (niz != nullptr)
	{
		delete[]niz;
		niz = nullptr;
	}
}

template<class T>
inline T Niz<T>::sumaElemenata() const
{
	T suma = 0; // Constructor sa jednim parametrom tipa int
	for (int i = 0; i < curr; i++)
		suma += niz[i]; // operator +=
	return suma; // Copy constructor
}
