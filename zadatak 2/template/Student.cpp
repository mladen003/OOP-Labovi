#include "Student.h"

Student::Student()
{
	ime = nullptr;
	prezime = nullptr;
	ID = 0;
	prosek = 0;
}

Student::Student(int ID, double prosek, const char* ime, const char* prezime)
{
	this->ID = ID;
	this->prosek = prosek;
	this->ime = copyString(ime);
	this->prezime = copyString(prezime);
}

Student::~Student()
{
	if (ime != nullptr) {
		delete[]ime;
		ime = nullptr;
	}
	if (prezime != nullptr) {
		delete[]prezime;
		prezime = nullptr;
	}
}

bool Student::operator>(const Student& desni)
{
	return this->prosek > desni.prosek;
}

bool Student::operator<(const Student& desni)
{
	return this->prosek < desni.prosek;
}

Student& Student::operator=(const Student& desni)
{
	// Provera adresa
	if (this == &desni)
		return *this;

	// Dealokacija this-a
	if (this->ime != nullptr)
	{
		delete[]ime;
		ime = nullptr;
	}
	if (this->prezime != nullptr)
	{
		delete[]prezime;
		prezime = nullptr;
	}

	// Kopiranje
	this->ID = desni.ID;
	this->prosek = desni.prosek;
	this->ime = copyString(desni.ime);
	this->prezime = copyString(desni.prezime);

	return *this;
}

char* Student::copyString(const char* original)
{
	if (original == nullptr)
		return nullptr;

	int n = 0;
	while (original[n] != '\0')
		n++;

	char* kopija = new char[n + 1];

	for (int i = 0; i < n; i++)
		kopija[i] = original[i];

	kopija[n] = '\0';

	return kopija;
}

ostream& operator<<(ostream& out, const Student& obj)
{
	return out << "\tIndex: " << obj.ID << endl
		<< "\tIme: " << (obj.ime == nullptr ? "/" : obj.ime) << endl
		<< "\tPrezime " << (obj.prezime == nullptr ? "/" : obj.prezime) << endl
		<< "\tProsek: " << obj.prosek;
}

istream& operator>>(istream& input, Student& obj)
{
	// Potencijalna dealokacija
	if (obj.ime != nullptr) {
		delete[]obj.ime;
		obj.ime = nullptr;
	}
	
	if (obj.prezime != nullptr) {
		delete[]obj.prezime;
		obj.prezime = nullptr;
	}
	// Ucitavanje
	char temp[100] = {};
	input >> obj.ID;
	input.getline(temp, 100);
	input.getline(temp, 100);
	obj.ime = Student::copyString(temp);
	input.getline(temp, 100);
	obj.prezime = Student::copyString(temp);
	input >> obj.prosek;

	return input;
}
