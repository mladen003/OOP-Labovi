#pragma once
#include <iostream>
using namespace std;
class Element
{
protected:
	int tip;
public:
	Element();
	Element(int i);
	inline int getTip() const
	{
		return tip;
	}
	virtual double vratiVrednost() = 0;
	virtual void stampanje(ostream& out);
	virtual Element* getCopy() const = 0;
};

