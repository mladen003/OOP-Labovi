#pragma once
#include <iostream>
using namespace std;

class SefUOblikuKocke
{
	int brBrava;
	int debljinaZida;
	int duzinaStranice;
	int gustinaMaterijala;
public:
	SefUOblikuKocke();
	SefUOblikuKocke(int n);
	SefUOblikuKocke(int brBrava, int debljinaZida, int duzinaStranice, int gustinaMaterijala);
	SefUOblikuKocke(const SefUOblikuKocke& obj);
	bool operator>(const SefUOblikuKocke& obj);
	SefUOblikuKocke& operator+=(const SefUOblikuKocke& obj);
	SefUOblikuKocke& operator=(const SefUOblikuKocke& obj);
	friend ostream& operator<<(ostream& out, const SefUOblikuKocke& obj);
	friend istream& operator>>(istream& input, SefUOblikuKocke& obj);
};

