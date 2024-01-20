#pragma once
#include <iostream>
using namespace std;

class Figura
{
protected:
	int n;
	double* niz;
public:
	Figura();
	Figura(int n);
	virtual ~Figura();
	virtual double povrsina();
	virtual void prikazi(ostream& output);
};

