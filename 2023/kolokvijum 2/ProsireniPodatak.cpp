#include "ProsireniPodatak.h"

ProsireniPodatak::ProsireniPodatak()
{
    temperatura = 0;
    vlaznost = 0;
    brzina = 0;
}

ProsireniPodatak::ProsireniPodatak(float temperatura, float vlaznost, float brzina)
{
    this->temperatura = temperatura;
    this->vlaznost = vlaznost;
    this->brzina = brzina;
}

bool ProsireniPodatak::operator>(const ProsireniPodatak& obj)
{
    return this->getFeelsLikeTemp() > obj.getFeelsLikeTemp();
}

float ProsireniPodatak::getFeelsLikeTemp() const
{
    return temperatura + 0.33 * vlaznost - 0.7 * brzina - 4;
}

ostream& operator<<(ostream& output, const ProsireniPodatak& obj)
{
    output << obj.temperatura << "\t" << obj.vlaznost << "\t" << obj.brzina;
    return output;
}

istream& operator>>(istream& input, ProsireniPodatak& obj)
{
    input >> obj.brzina;
    input >> obj.temperatura;
    input >> obj.vlaznost;
    return input;
}

float& operator+=(float& a, const ProsireniPodatak& obj)
{
    a += obj.getFeelsLikeTemp();

    return a;
}
