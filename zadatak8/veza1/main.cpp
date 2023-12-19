#include "Paragraph.h"
int main()
{
	fstream f;
	f.open("fajl.txt");
	int m;
	f >> m;
	
	Paragraph* p = new Paragraph();
	for (int i = 0; i < m; i++) {
		String* s = new String();
		f >> *s;
		p->dodavanjeStringa(*s);
	}
	f.close();

	f.open("fajl.txt");
	f >> m;
	String* a = new String();
	f >> *a;
	String* b = new String();
	f >> *b;
	String* c = new String();
	f >> *c;
	String* d = new String();
	f >> *d;
	String* e = new String();
	f >> *e;
	f.close();

	cout << "Poziv funkcije koja pretvara prvo slovo u veliko za svaki string: " << endl;
	cout << a->prvoSlovo();
	cout << b->prvoSlovo();
	cout << c->prvoSlovo();
	cout << d->prvoSlovo();
	cout << e->prvoSlovo() << endl;

	cout << "Poziv funkcije koja pretvara sva slova u velika za svaki string: " << endl;
	cout << a->svaVelikaSlova();
	cout << b->svaVelikaSlova();
	cout << c->svaVelikaSlova();
	cout << d->svaVelikaSlova();
	cout << e->svaVelikaSlova() << endl;

	cout << "Poziv funkcije padright za svaki string: " << endl;
	cout << a->PadRight('x', 10);
	cout << b->PadRight('x', 10);
	cout << c->PadRight('x', 10);
	cout << d->PadRight('x', 10);
	cout << e->PadRight('x', 10) << endl;;

	cout << "Paragraf izgleda ovako :" << endl;
	p->prikaz();

	// Destruktori:


	if (e != nullptr) {
		delete e;
		e = nullptr;
	}
	
	if (d != nullptr) {
		delete d;
		d = nullptr;
	}
	
	if (c != nullptr) {
		delete c;
		c = nullptr;
	}
	
	if (b != nullptr) {
		delete b;
		b = nullptr;
	}

	if (a != nullptr) {
		delete a;
		a = nullptr;
	}
	
	if (p != nullptr) {
		delete p;
		p = nullptr;
	}
	

	return 0;
}
