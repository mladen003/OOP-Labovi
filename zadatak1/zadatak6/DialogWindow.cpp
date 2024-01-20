#include "DialogWindow.h"

DialogWindow::DialogWindow()
	: Window()
{}

DialogWindow::~DialogWindow()
{}

void DialogWindow::draw()
{
	cout << "DialogWindow nacrtan" << endl;
}

int DialogWindow::confirm()
{
	state = 0;
	return 1;
}

int DialogWindow::cancel()
{
	state = 0;
	return 0;
}

