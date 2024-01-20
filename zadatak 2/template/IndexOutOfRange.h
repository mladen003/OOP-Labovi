#pragma once
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class IndexOutOfRangeException
{
private:
	int index;
	int upperRange;
	int lowerRange;

public:
	IndexOutOfRangeException(int index, int lowerRange, int upperRange);

	string getMessage() const;
	friend ostream& operator<<(ostream& output, const IndexOutOfRangeException& e);
};