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
	Niz(const Niz& obj);
	~Niz();
	T& operator=(const T& obj);
	T operator[](int i);
	int getSize();
	Niz operator+(const Niz& obj);
	void ucitavanjeElemenata(const T& obj);

	template<class T>
	friend ostream& operator<<(ostream& output, const Niz<T>& obj);

};

template<class T>
inline Niz<T>::Niz()
{
	niz = new T[10];
	n = 10;
	curr = 0;
}

template<class T>
inline Niz<T>::Niz(int n)
{
	this->n = n;
	niz = new T[n];
	curr = 0;
}

template<class T>
inline Niz<T>::Niz(const Niz& obj)
{
	this->n = obj.n;
	this->curr = obj.curr;

	this->niz = new T[obj.n];
	for (int i = 0; i < obj.curr; i++)
		this->niz[i] = obj.niz[i];
}

template<class T>
inline Niz<T>::~Niz()
{
	if (niz != nullptr)
	{
		delete[] niz;
		niz = nullptr;
	}
}

template<class T>
inline T& Niz<T>::operator=(const T& obj)
{
	if (this == &obj)
		return *this;

	this->n = obj.n;
	this->curr = obj.curr;

	if (this->niz != nullptr) {
		delete[]niz;
		niz = nullptr;
	}

	for (int i = 0; i < obj.curr; i++)
		this->niz[i] = obj.niz[i];
}

template<class T>
inline T Niz<T>::operator[](int i)
{
	if (i < curr)
		return niz[i];
}

template<class T>
inline int Niz<T>::getSize()
{
	return curr;
}

template<class T>
inline Niz<T> Niz<T>::operator+(const Niz<T>& obj)
{
	Niz<T> a = obj.curr > this->curr ? *this : obj;
	const  Niz<T>* b = obj.curr > this->curr ? &obj : this;

	for (int i = 0; i < a.curr; i++)
		a.niz[i] = a.niz[i] + b->niz[i];

	return a;
}

template<class T>
inline void Niz<T>::ucitavanjeElemenata(const T& obj)
{
	if (curr < n) {
		niz[curr] = obj;
			curr++;
	}
}

template<class T>
inline ostream& operator<<(ostream& output, const Niz<T>& obj)
{
	output << "N: " << obj.n << endl
		<< "Curr: " << obj.curr << endl
		<< "Elementi:" << endl;

	for (int i = 0; i < obj.curr; i++)
		output << obj.niz[i] << endl;

	return output;
}
