#pragma once
#include"Zemlja.h"
#include"Voda.h"
using namespace std;
class Put
{
	Element** niz;
	int n;
public:
	Put();
	Put(int n);
	virtual ~Put();
	Put(const Put& original);
	Put& operator=(const Put& original);
	void postaviElement(int indeks, Element& objekt);
	void brElemenata();
	double prosecnaNadmorskaVisina() const;
	friend ostream& operator<<(ostream& out, const Put& objekat);
	friend istream& operator>>(istream& input, Put& objekat);

private:
	void alociraj(int n = 0, Element** niz = nullptr);
	void dealociraj();
};

