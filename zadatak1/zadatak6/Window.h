#pragma once
#include <iostream>
using namespace std;
#include <fstream>

class Window
{
protected:
	char* title;
	int state;
public:
	Window();
	Window(char* naziv);
	virtual ~Window();
	virtual void draw(ostream& ispis);
	void open();
	void close();
};

