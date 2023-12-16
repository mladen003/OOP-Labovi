#include "Skup.h"
Skup::Skup()
{
	n = 0;
	curr = 0;
	niz = nullptr;
}
Skup::Skup(int n)
{
	this->n = n;
	this->curr = 0;
	this->niz = new Complex[n];
}
Skup::Skup(const Skup& a)
{
	this->n = a.n;
	this->curr = a.curr;
	this->niz = nullptr;
	if (a.niz != nullptr) {
		this->niz = new Complex[n];
		for (int i = 0; i < a.curr; i++)
			this->niz[i] = a.niz[i];
	}
}
Skup::~Skup()
{
	if (niz != nullptr) {
		delete[]niz;
		niz = nullptr;
	}
}
void Skup::izbacivanjeDuplikata()
{
	int i, j;
	for (i = 0; i < curr - 1; i++)
		for (j = i + 1; j < curr; j++)
			if (niz[i] == niz[j])
				izbaci(j--);			
}
int Skup::pripadnostElementa(const Complex& el)
{
	for (int i = 0; i < curr; i++) {
		if (niz[i] == el)
			return i;
	}
	return -1;
}
void Skup::ucitavanjeElemenata()
{
	for (int i = 0; i < curr; i++)
		cin >> niz[i];

}
void Skup::ispisElemenata()
{
	if (niz != nullptr) {
		for (int i = 0; i < curr; i++)
			cout << niz[i] << " , ";
	}
}
void Skup::uredjeneNiza()
{
	int i, j;
	Complex pom;
	for (i = 0; i < curr - 1; i++) {
		for (j = i + 1; j < curr; j++) {
			if (niz[i] > niz[j]) {
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
		}
	}
}
Skup Skup::razlika(const Skup& a) const
{
	Skup razlika(*this);
	for (int i = 0; i < razlika.curr; i++) {
		int j = 0;
		while (j < a.curr && a.niz[j] != razlika.niz[i])
			j++;
		if (j < a.curr)
			razlika.izbaci(i--);
	}
	return razlika;
}
Skup Skup::unija(const Skup& a)
{
	Skup unija(*this);
	for (int i = 0; i < a.curr; i++) {
		int j = 0;
		while (j < curr && unija.niz[j] != a.niz[i])
			j++;
		if (j == curr)
			unija.ubaci(a.niz[i]);
	}	
	return unija;
}

Skup Skup::presek(const Skup& a)
{
	Skup thisUnijaA = this->unija(a);
	Skup thisRazlikaA = this->razlika(a);
	Skup ARazlikaThis = a.razlika(*this);

	return thisUnijaA.razlika(thisRazlikaA).razlika(ARazlikaThis);
}

Complex Skup::izbaci(int index)
{
	Complex izbacen = this->niz[index]; // copy constructor klase Complex

	for (int i = index; i < this->curr - 1; i++)
		this->niz[i] = this->niz[i + 1]; // operator dodele klase Complex

	this->curr--;

	return izbacen;
}
void Skup::dupliraj()
{
	int newN = this->n ? this->n << 1 : 1;

	Complex* oldNiz = this->niz;

	this->niz = new Complex[newN];

	for (int i = 0; i < this->curr; i++)
		this->niz[i] = oldNiz[i];

	this->n = newN;

	if(oldNiz != nullptr)
		delete[] oldNiz;
}
void Skup::ubaci(const Complex& a)
{
	if (n == curr)
		dupliraj();

	niz[curr++] = a;
}

Skup& Skup::operator=(const Skup& desni)
{
	// Provera da li se radi o istim memorijskim lokacijama
	// Ovo se proverava zato sto moramo da dealociramo memoriju
	// Ukoliko bi odradili a = a, memorija bi bila ista, pa dealociranjem this (levog a)
	// Odradicemo i dealokaciju desnog a, jer pokazuju na isto
	// Pa posle ne bismo mogli bilo sta da prekopiramo, jer je ista memorija dealocirana
	if (this == &desni)
		return *this;

	// Dealokacija dinamicke memorije u okviru this-a (levog operanda)
	if (niz != nullptr)
		delete[] niz;

	// Alokacija/Kopiranje desnog u levi (this) operand
	niz = nullptr;
	n = desni.n;
	curr = desni.curr;

	if (desni.niz != nullptr)
	{
		niz = new Complex[n];
		for (int i = 0; i < curr; i++)
			niz[i] = desni.niz[i];
	}

	// Vraca se instanca this-a kako bi operator mogli da nastavljamo
	// a = b = c = d
	// a = (b = (c = d))
	// Radilo bi i da nemamo X& kao povratnu vrednost (void), ali onda ne bismo mogli da nadovezujemo operatore
	// Radilo bi i da vracamo X, ali onda bi se pozivao i copy constrftor, jer vracamo po vrednosti
	return *this;
}

ostream& operator<<(ostream& ispis, const Skup& objekat)
{
	ispis << objekat.n << endl << objekat.curr << endl;
	for (int i = 0; i < objekat.curr; i++)
		ispis << objekat.niz[i] << endl;
	return ispis;
}

istream& operator>>(istream& upis, Skup& objekat)
{
	int n, curr;
	upis >> n;
	upis >> curr;

	for (int i = 0; i < curr; i++)
	{
		Complex privremeniKompleks;
		upis >> privremeniKompleks;
		objekat.ubaci(privremeniKompleks);
	}

	return upis;
}

