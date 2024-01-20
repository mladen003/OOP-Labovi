#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class ProsireniPodatak {
	float temperatura;
	float vlaznost;
	float brzina;
public:
	ProsireniPodatak();
	ProsireniPodatak(float temperatura, float vlaznost, float brzina);

	friend ostream& operator<<(ostream& output, const ProsireniPodatak& obj);
	friend istream& operator>>(istream& input, ProsireniPodatak& obj);
	friend float& operator+=(float& a, const ProsireniPodatak& obj);
	bool operator>(const ProsireniPodatak& obj);

private:
	float getFeelsLikeTemp() const;
};