#include "IndexOutOfRange.h"
#include "Niz.h"
#include "Student.h"

#include <fstream>

int main() 
{
	for (int i = 0; i < 2; i++)
	{
		try {
			fstream f;
			cout << "Studenti" << endl;

			Niz<Student, 5> studenti;

			f.open("studenti.txt");

			studenti.ucitavanjeElemenata(f);

			f.close();

			cout << "Nesortiran studenti:" << endl;
			studenti.prikazNiza(cout);

			studenti.uredjivanjeNiza();

			cout << "Sortiran studenti:" << endl;
			studenti.prikazNiza(cout);

			try {
				cout << "Najbolji student je:" << endl << studenti[0] << endl;
			}
			catch (IndexOutOfRangeException* e)
			{
				cout << *e;
				delete e;
			}
			catch (const char* e)
			{
				cout << e;
			}

			cout << "Doubleovi" << endl;

			Niz<double, 20> doubleovi;

			f.open("doubleovi.txt");

			doubleovi.ucitavanjeElemenata(f);

			f.close();

			cout << "Nesortiran doubleovi:" << endl;
			doubleovi.prikazNiza(cout);

			doubleovi.uredjivanjeNiza();

			cout << "Sortiran doubleovi:" << endl;
			doubleovi.prikazNiza(cout);

			try {
				cout << "Najbolji double je:" << endl << doubleovi[10000] << endl;
			}
			catch (IndexOutOfRangeException* e)
			{
				cout << *e;
				delete e;
			}

			if(i == 0)
				cout << "1000. double:" << doubleovi[1000] << endl;

			Niz<Student, 1> studenti2;

			studenti2.ucitavanjeElemenata(cin);
		}
		catch (const char* e)
		{
			cout << e << endl;
		}
	}

	return 0;
}