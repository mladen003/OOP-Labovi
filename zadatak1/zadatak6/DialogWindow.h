#pragma once
#include "Window.h"

class DialogWindow : public Window
{
public:
	DialogWindow();
	~DialogWindow();
	void draw();
	int confirm();
	int cancel();
};

