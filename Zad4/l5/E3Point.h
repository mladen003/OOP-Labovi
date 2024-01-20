#pragma once
#include <iostream>
using namespace std;

class E3Point
{
	double x;
	double y;
	double z;
	char* ime;
public:
	E3Point();
	E3Point(const char* ime, double x, double y, double z);
	E3Point(const E3Point& obj);
	~E3Point();
	E3Point operator+(const E3Point& obj);
	E3Point& operator=(const E3Point& obj);
	friend ostream& operator<<(ostream& out, const E3Point& obj);
	friend istream& operator>>(istream& input, E3Point& obj);
};

