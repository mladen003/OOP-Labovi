#include "IndexOutOfRange.h"

ostream& operator<<(ostream& output, const IndexOutOfRangeException& e)
{
	return output << e.getMessage();
}

IndexOutOfRangeException::IndexOutOfRangeException(int index, int lowerRange, int upperRange)
{
	this->index = index;
	this->lowerRange = lowerRange;
	this->upperRange = upperRange;
}

string IndexOutOfRangeException::getMessage() const
{
	stringstream ss;

	ss	<< "Index passed '" << index
		<<"' is out of allowed range ["
		<< lowerRange << ", "
		<< upperRange << "]";

	return ss.str();
}
