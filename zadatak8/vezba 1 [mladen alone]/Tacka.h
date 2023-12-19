#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Tacka
{
	double x;
	double y;
	double z;
	Tacka mnozenjeSkalarom(double n) const;
	double moduo() const;
public:
	Tacka(const Tacka& desni);
	Tacka();
	Tacka(double x, double y, double z);
	~Tacka();
	Tacka& operator=(const Tacka& original);
	friend ostream& operator<<(ostream& izlaz, const Tacka& obj);
	friend istream& operator>>(istream& ulaz, Tacka& obj);
	Tacka operator+(const Tacka& desni);
	Tacka operator-(const Tacka& desni);
	Tacka operator*(double x);
	friend Tacka operator*(double x, const Tacka& desni);
	bool operator==(const Tacka& desni);
	bool operator>(const Tacka& desni);
	double operator[](double x);
	Tacka operator*(const Tacka& obj);
	double operator%(const Tacka& obj);
	Tacka& operator+=(double m);
	Tacka& operator*=(double m);
};

