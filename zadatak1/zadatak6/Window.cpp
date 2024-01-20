#include "Window.h"

Window::Window()
{
	state = 0;
	title = nullptr;
}

Window::Window(char* naziv)
{
	int n = 0;
	while (naziv[n] != '\0')
		n++;
	title = new char[n + 1];
	for (int i = 0; i < n; i++)
		title[i] = naziv[i];
	title[n] = '\0';

}

Window::~Window()
{
	if (title != nullptr) {
		delete[]title;
		title = nullptr;
	}
}

void Window::draw(ostream& ispis)
{
	ispis << state << endl;
	if (title != nullptr) {

		int n=0;
		while (title[n] != '\0')
			n++;

		for (int i = 0; i < n; i++)
			ispis << title[i];
		ispis << endl;
	}
}

void Window::open()
{
	state = 1;
}

void Window::close()
{
	state = 0;
}
