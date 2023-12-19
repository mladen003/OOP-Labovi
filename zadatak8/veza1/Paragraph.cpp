#include "Paragraph.h"

Paragraph::Paragraph()
{
	max = 0;
	trbr = 0;
	niz = nullptr;
}

Paragraph::Paragraph(int max)
{
	this->max = max;
	trbr = 0;
	niz = new String[max];
}

Paragraph::Paragraph(const Paragraph& desni)
{
	max = desni.max;
	trbr = desni.trbr;

	if (niz != nullptr) {
		delete [] niz;
		niz = nullptr;
	}
	niz = new String[desni.max];

	for (int i = 0; i < desni.trbr; i++)
		niz[i] = desni.niz[i];
}

Paragraph::~Paragraph()
{
	if (niz != nullptr) {
		delete[]niz;
		niz = nullptr;
	}
}

void Paragraph::dodavanjeStringa(const String& s)
{
	if (trbr == max) {
		int noviMax = this->max > 0 ? max * 2 : 1;

		String* stariNiz = this->niz;

		this->niz = new String[noviMax];

		for (int i = 0; i < this->trbr; i++)
			this->niz[i] = stariNiz[i];

		this->max = noviMax;

		if (stariNiz != nullptr)
			delete[] stariNiz;
	}
	niz[trbr++] = s;
}

void Paragraph::prikaz()
{
	for (int i = 0; i < trbr; i++)
		cout << niz[i];
}




