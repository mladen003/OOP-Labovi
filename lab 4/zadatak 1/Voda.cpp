#include "Voda.h"

Voda::Voda()
	: Element(2)
{
	dubina = 0;

}

Voda::Voda(double l)
	: Element(2)
{
	dubina = l;
}

double Voda::vratiVrednost()
{
	return -dubina;
}

void Voda::stampanje(ostream& out)
{
	Element::stampanje(out);
	out << " dubina: " << dubina;
}

Element* Voda::getCopy() const
{
	return new Voda(*this);
}

istream& operator>>(istream& inp, Voda& objekat)
{
	inp >> objekat.dubina;
	return inp;
}
