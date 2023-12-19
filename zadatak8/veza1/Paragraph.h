#pragma once
#include "String.h"

class Paragraph
{
	int max;
	int trbr;
	String* niz;
public:
	Paragraph();
	Paragraph(int max);
	Paragraph(const Paragraph& desni);
	~Paragraph();
	void dodavanjeStringa(const String& s);
	void prikaz();
};

