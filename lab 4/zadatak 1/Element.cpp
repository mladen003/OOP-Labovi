#include "Element.h"

Element::Element()
{
	tip = 0;
}

Element::Element(int tip)
{
	this->tip = tip;
}

void Element::stampanje(ostream& out)
{
	out << tip;
}
