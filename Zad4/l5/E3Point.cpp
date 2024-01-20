#include "E3Point.h"

E3Point::E3Point()
{
	x = 0;
	y = 0;
	z = 0;
	ime = nullptr;
}

E3Point::E3Point(const char* ime, double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	int n = 0;
	while (ime[n] != '\0')
		n++;
	this->ime = new char[n + 1];
	for (int i = 0; i < n; i++)
		this->ime[i] = ime[i];
	this->ime[n] = '\0';
}

E3Point::E3Point(const E3Point& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;
	this->ime = nullptr;


	if (obj.ime != nullptr) {
		int n = 0;
		while (obj.ime[n] != '\0')
			n++;
		this->ime = new char[n + 1];
		for (int i = 0; i < n; i++)
			this->ime[i] = obj.ime[i];
		this->ime[n] = '\0';
	}
}

E3Point::~E3Point()
{
	if (ime != nullptr) {
		delete[]ime;
		ime = nullptr;
	}
}

E3Point E3Point::operator+(const E3Point& obj)
{

	E3Point a(*this);
	a.x += obj.x;
	a.y += obj.y;
	a.z += obj.z;

	if (obj.ime != nullptr) {
		int n = 0;
		int m = 0;
		while (obj.ime[m] != '\0')
			m++;
		while (this->ime[n] != '\0')
			n++;

		if (a.ime != nullptr) {
			delete[] a.ime;
			a.ime = nullptr;
		}
		a.ime = new char[n + m + 1];
		for (int i = 0; i < n; i++)
			a.ime[i] = this->ime[i];

		for (int j = 0; j < m; j++)
			a.ime[n + j] = obj.ime[j];

		a.ime[n + m] = '\0';
	}

	return a;
}

E3Point& E3Point::operator=(const E3Point& obj)
{
	if (this == &obj)
		return *this;

	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;

	if (this->ime != nullptr) {
		delete[]ime;
		ime = nullptr;
	}
	if (obj.ime != nullptr) {
		int n = 0;
		while (obj.ime[n] != '\0')
			n++;
		this->ime = new char[n + 1];
		for (int i = 0; i < n; i++)
			this->ime[i] = obj.ime[i];
		this->ime[n] = '\0';
	}
}

ostream& operator<<(ostream& out, const E3Point& obj)
{
	out << "Ime: " << (obj.ime != nullptr ? obj.ime : "/") << endl << "Koordinate: "
		<< "( x, y, z ) = " << " ( " << obj.x << ", " << obj.y << ", " << obj.z << " )";
	return out;
}

istream& operator>>(istream& input, E3Point& obj)
{
	input >> obj.x;
	input >> obj.y;
	input >> obj.z;
	char S[100] = {};
	input.getline(S, 100);
	input.getline(S, 100);

	if (obj.ime != nullptr)
	{
		delete[]obj.ime;
		obj.ime = nullptr;
	 }

	int n = 0;
	while (S[n] != '\0')
		n++;

	obj.ime = new char[n + 1];
	for (int i = 0; i < n; i++)
		obj.ime[i] = S[i];
	obj.ime[n] = '\0';
	
	return input;
}
