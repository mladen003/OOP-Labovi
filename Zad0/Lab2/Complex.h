#pragma once
#include <iostream>
using namespace std;
class Complex
{
	double re;
	double im;
public:
	Complex();
	Complex(double re, double im = 0);
	~Complex();
	friend ostream& operator<<(ostream& levi, const Complex& desni);
	friend istream& operator>>(istream& levi, Complex& desni);
	Complex operator+(const Complex& desni);
	Complex operator-(const Complex& desni);

	double operator[](int a);
	double operator[](const Complex& a) const;
	double operator()(const Complex& z);
	Complex operator*(const Complex& z);
	bool operator==(const Complex& a);
	bool operator!=(const Complex& a);
	bool operator<(const Complex& a);
	bool operator>(const Complex& a);
	bool operator<=(const Complex& a);
	bool operator>=(const Complex& a);

private:
	inline static char signOf(double value) { return value >= 0 ? '+' : '-'; }

};


