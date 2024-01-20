#include "ZlatnaPoluga.h"

ZlatnaPoluga::ZlatnaPoluga()
{
    finoca = 0;
    masa = 0;
}

ZlatnaPoluga::ZlatnaPoluga(int n)
{
    finoca = 0;
    masa = 0;
}

ZlatnaPoluga::ZlatnaPoluga(int finoca, double masa)
{
    this->finoca = finoca;
    this->masa = masa;
}

ZlatnaPoluga::ZlatnaPoluga(const ZlatnaPoluga& obj)
{
    this->finoca = obj.finoca;
    this->masa = obj.masa;
}

bool ZlatnaPoluga::operator>(const ZlatnaPoluga& obj)
{
    return this->masa > obj.masa;
}

ZlatnaPoluga& ZlatnaPoluga::operator+=(const ZlatnaPoluga& obj)
{
    this->finoca += obj.finoca;
    this->masa += obj.masa;
    return *this;
}

ZlatnaPoluga& ZlatnaPoluga::operator=(const ZlatnaPoluga& obj)
{
    this->finoca = obj.finoca;
    this->masa = obj.masa;
    return *this;
}

ostream& operator<<(ostream& out, const ZlatnaPoluga& obj)
{
    out << "Masa: " << obj.masa << ", Finoca: " << obj.finoca;
    return out;
}

istream& operator>>(istream& input, ZlatnaPoluga& obj)
{
    input >> obj.finoca;
    input >> obj.masa;
    return input;
}
