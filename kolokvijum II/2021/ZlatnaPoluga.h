#pragma once
#include <iostream>
using namespace std;

class ZlatnaPoluga
{
	int finoca;
	double  masa;
public:
	ZlatnaPoluga();
	ZlatnaPoluga(int n);
	ZlatnaPoluga(int finoca, double masa);
	ZlatnaPoluga(const ZlatnaPoluga& obj);
	bool operator>(const ZlatnaPoluga& obj);
	ZlatnaPoluga& operator+=(const ZlatnaPoluga& obj);
	ZlatnaPoluga& operator=(const ZlatnaPoluga& obj);
	friend ostream& operator<<(ostream& out, const ZlatnaPoluga& obj);
	friend istream& operator>>(istream& input, ZlatnaPoluga& obj);
};

