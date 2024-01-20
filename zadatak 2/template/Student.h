#pragma once
#pragma once
#include <iostream>

using namespace std;
class Student
{
	char* ime;
	char* prezime;
	int ID;
	double prosek;
public:
	Student();
	Student(int ID, double prosek, const char* ime, const char* prezime);
	~Student();
	bool operator>(const Student& desni);
	bool operator<(const Student& desni);
	Student& operator=(const Student& desni);
	friend ostream& operator<<(ostream& out, const Student& obj);
	friend istream& operator>>(istream& input, Student& obj);

	static char* copyString(const char* original);

};

