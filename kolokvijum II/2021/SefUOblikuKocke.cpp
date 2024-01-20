#include "SefUOblikuKocke.h"

SefUOblikuKocke::SefUOblikuKocke()
{
	brBrava = 0;
	debljinaZida = 0;
	duzinaStranice = 0;
	gustinaMaterijala = 0;
}

SefUOblikuKocke::SefUOblikuKocke(int n)
{
	brBrava = 0;
	debljinaZida = 0;
	duzinaStranice = 0;
	gustinaMaterijala = 0;
}

SefUOblikuKocke::SefUOblikuKocke(int brBrava, int debljinaZida, int duzinaStranice, int gustinaMaterijala)
{
	this->brBrava = brBrava;
	this->debljinaZida = debljinaZida;
	this->duzinaStranice = duzinaStranice;
	this->gustinaMaterijala = gustinaMaterijala;
}

SefUOblikuKocke::SefUOblikuKocke(const SefUOblikuKocke& obj)
{
	this->brBrava = obj.brBrava;
	this->debljinaZida = obj.debljinaZida;
	this->duzinaStranice = obj.duzinaStranice;
	this->gustinaMaterijala = obj.gustinaMaterijala;
}

bool SefUOblikuKocke::operator>(const SefUOblikuKocke& obj)
{
	return this->brBrava * this->gustinaMaterijala > obj.brBrava * obj.gustinaMaterijala;
}

SefUOblikuKocke& SefUOblikuKocke::operator+=(const SefUOblikuKocke& obj)
{
	this->brBrava = max(brBrava, obj.brBrava);
	this->debljinaZida = max(debljinaZida, obj.debljinaZida);
	this->duzinaStranice = max(duzinaStranice, obj.duzinaStranice);
	this->gustinaMaterijala = max(gustinaMaterijala, obj.gustinaMaterijala);
	return *this;
}

SefUOblikuKocke& SefUOblikuKocke::operator=(const SefUOblikuKocke& obj)
{
	this->brBrava = obj.brBrava;
	this->debljinaZida = obj.debljinaZida;
	this->duzinaStranice = obj.duzinaStranice;
	this->gustinaMaterijala = obj.gustinaMaterijala;
	return *this;
}

ostream& operator<<(ostream& out, const SefUOblikuKocke& obj)
{
	out << "Br brava: " << obj.brBrava << ", Debljina zida: " << obj.debljinaZida << ", Duzina stranice: "
		<< obj.duzinaStranice << ", Gustina materijala: " << obj.gustinaMaterijala;
	return out;
}

istream& operator>>(istream& input, SefUOblikuKocke& obj)
{
	input >> obj.brBrava >> obj.debljinaZida >> obj.duzinaStranice >> obj.gustinaMaterijala;
	return input;
}
