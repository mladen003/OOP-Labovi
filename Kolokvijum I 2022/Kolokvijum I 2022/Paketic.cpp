#include "Paketic.h"

Paketic::Paketic()
{
	adresa = 0;
	boja = nullptr;
}

Paketic::Paketic(int adresa, const char* boja)
{
	this->adresa = adresa;

	if (boja != nullptr) {
		int n = 0;
		while (boja[n] != '\0')
			n++;

		this->boja = new char[n + 1];
		for (int i = 0; i < n; i++)
			this->boja[i] = boja[i];
		this->boja[n] = '\0';
	}
	else
		this->boja = nullptr;
}

Paketic::~Paketic()
{
	if (boja != nullptr) {
		delete[] boja;
		boja = nullptr;
	}
}
