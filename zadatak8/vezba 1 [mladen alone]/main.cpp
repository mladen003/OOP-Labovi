#include "Vektor.h"

int main()
{
	Vektor* viktor = new Vektor();
	cin >> *viktor;

	cout << *viktor << endl;

	viktor->uredjenjeNiza();
	cout << *viktor << endl;

	cout << "Drugi vektor: ";

	Vektor* vaktor = new Vektor();

	cin >> *vaktor;

	cout << *vaktor << endl;

	cout << "Vaktor dot Viktor: " << vaktor->skalarniProizvod(*viktor) << endl;

	cout << "[Vaktor] Element najblizi sr. vrednosti: " << vaktor->vrednostElementa(vaktor->srVrednost()) << endl;
	cout << "[Viktor] Element najblizi sr. vrednosti: " << viktor->vrednostElementa(viktor->srVrednost()) << endl;

	if (vaktor != nullptr) {
		delete vaktor;
		vaktor = nullptr;
	}

	if (viktor != nullptr) {
		delete viktor;
		viktor = nullptr;
	}

	return 0;
}