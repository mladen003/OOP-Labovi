#include "DialogWindow.h"
#include "DocumentWindow.h"

int main()
{
	int n = 2018;
	Window** prozori = new Window * [n];
	for (int i = 0; i < n; i += 2) {
		prozori[i] = new DialogWindow();
		prozori[i + 1] = new DocumentWindow();
	}

	for (int i = 0; i < n; i++) {
		prozori[i]->draw(cout);
	}


	return 0;
}