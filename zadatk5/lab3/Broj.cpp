#include "Broj.h"

Broj::Broj()
{
	this->vrednost = 0;
	this->vrsta = nullptr;
}

Broj::Broj(double vrednost, const char* vrsta)
{
	this->vrednost = vrednost;

	int n = 0;
	while (vrsta[n] != '\0')
		n++;

	this->vrsta = new char[n + 1];

	for (int i = 0; i < n; i++)
		this->vrsta[i] = vrsta[i];
	this->vrsta[n] = '\0';
}

Broj::~Broj()
{
	if (vrsta != nullptr) {
		delete[] vrsta;
		vrsta = nullptr;
	}
}

int Broj::poredjenjeBrojeva(const Broj& desni)
{
	if (this->vrednost > desni.vrednost)
		return 1;
	else if (this->vrednost < desni.vrednost)
		return -1;
	else return 0;
}

void Broj::print(ostream& ispis)
{
	ispis << "[" << (vrsta != nullptr ? vrsta : "Nepoznato") << "] " << vrednost;
}



