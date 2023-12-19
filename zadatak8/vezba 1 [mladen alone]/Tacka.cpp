#include "Tacka.h"
Tacka::Tacka()
{
	x = 0;
	y = 0;
	z = 0;
}

Tacka::Tacka(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Tacka::~Tacka()
{
}

Tacka& Tacka::operator=(const Tacka& original)
{
	// Poredjenja adresa, ukoliko bude levi = desni
	if (this == &original)
		return *this;

	// dealokacija

	// alokacija
	this->x = original.x;
	this->y = original.y;
	this->z = original.z;

	return *this;
}

double Tacka::moduo() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Tacka::Tacka(const Tacka& desni)
{
	this->x = desni.x;
	this->y = desni.y;
	this->z = desni.z;
}

Tacka Tacka::mnozenjeSkalarom(double n) const
{
	return Tacka(x*n,y*n,z*n);
}

Tacka Tacka::operator+(const Tacka& desni)
{
	return Tacka(x+desni.x, y+desni.y, z+desni.z);
}

Tacka Tacka::operator-(const Tacka& desni)
{
	return Tacka(x - desni.x, y - desni.y, z - desni.z);
}

Tacka Tacka::operator*(double x)
{

	return this->mnozenjeSkalarom(x);
}

bool Tacka::operator==(const Tacka& desni)
{
	
	return x == desni.x && y == desni.y && z == desni.z;
}

bool Tacka::operator>(const Tacka& desni)
{
	return this->moduo() > desni.moduo();
}

double Tacka::operator[](double n)
{
	return pow(pow(x, n) + pow(y, n) + pow(z, n), 1 / n);
}

Tacka Tacka::operator*(const Tacka& obj)
{
	return Tacka(x * obj.x, y * obj.y, z * obj.z);
}

double Tacka::operator%(const Tacka& obj)
{
	return x * obj.x + y * obj.y + z * obj.z;
}

Tacka& Tacka::operator+=(double m)
{
	x += m;
	y += m;
	z += m;

	return *this;
}

Tacka& Tacka::operator*=(double m)
{
	x *= m;
	y *= m;
	z *= m;

	return *this;
}

ostream& operator<<(ostream& izlaz, const Tacka& obj)
{
	izlaz << obj.x << " " << obj.y << " " << obj.z;
	return izlaz;
}

istream& operator>>(istream& ulaz, Tacka& obj)
{
	ulaz >> obj.x;
	ulaz >> obj.y;
	ulaz >> obj.z;
	return ulaz;
}

Tacka operator*(double x, const Tacka& desni)
{
	return desni.mnozenjeSkalarom(x);
}
