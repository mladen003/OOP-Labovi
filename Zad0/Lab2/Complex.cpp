#include "Complex.h"
Complex::Complex()
{
	re = 0;
	im = 0;
}
Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = im;
}
Complex::~Complex()
{

}
ostream& operator<<(ostream& levi, const Complex& desni)
{
	levi << desni.re << " " << desni.signOf(desni.im) << " " << fabs(desni.im) << " i";
	return levi;
}

istream& operator>>(istream& levi, Complex& desni)
{
	char temp[100] = "";
	levi >> desni.re;

	// znak
	levi >> temp;
	levi >> desni.im;

	if (temp[0] == '-')
		desni.im = -desni.im;

	// imaginarna jedinica
	levi >> temp;

	return levi;
}
Complex Complex :: operator+(const Complex& desni)
{
	// Complex a(*this);
	Complex a = *this; // ovo je isto poziv kopi konstruktora

	a.re += desni.re; 
	a.im += desni.im;

	return a;
	// x.re = this->re + desni.re;
	// x.im = this->im + desni.im;
	// return x;
	// return Complex(this->re + desni.re, this->im + desni.im);
	
}
Complex Complex :: operator-(const Complex& desni)
{
	return Complex(this->re - desni.re, this->im - desni.im);
}
double Complex::operator[](int n)
{
	return pow((pow(re, n) + pow(im, n)), (double)1/n);
}

double Complex::operator[](const Complex& a) const
{
	return sqrt(pow(re - a.re, 2) + pow(im - a.im, 2));
}

double Complex::operator()(const Complex& z)
{
	return re * z.re + im * z.im;
}

Complex Complex::operator*(const Complex& z)
{
	return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
}

bool Complex::operator==(const Complex& a)
{
	return re == a.re && im == a.im;
}
bool Complex::operator!=(const Complex& a)
{
	return !(*this == a);
}

bool Complex::operator<(const Complex& a)
{
	return (*this)[2] < a[2];
}

bool Complex::operator>(const Complex& a)
{
	return (*this)[2] > a[2];
}

bool Complex::operator<=(const Complex& a)
{
	return (*this) < a || (*this) == a;
}

bool Complex::operator>=(const Complex& a)
{
	return (*this) > a || (*this) == a;
}
