#include "Karta.h"

Karta::Karta()
{
	IDkarte = 0;
	redniBrDana = 0;
	popust = 0;
}

Karta::Karta(int IDkarte, int redniBrDana, double popust)
{
	this->IDkarte = IDkarte;
	this->redniBrDana = redniBrDana;
	this->popust = popust;
}

Karta::Karta(const Karta& obj)
{
	this->IDkarte = obj.IDkarte;
	this->redniBrDana = obj.redniBrDana;
	this->popust = obj.popust;
}

Karta::~Karta()
{
}


