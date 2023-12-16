#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Vektor
{
	int* niz;
	int n;
public:
	Vektor();
	Vektor(int n);
	~Vektor();
	inline void kElelemnt(int k)
	{
		n = k;
	}
	inline int vrednostKelementa(int k) const
	{
		return niz[k];
	}
	void uredjenjeNiza();
	double skalarniProizvod();
	
};

