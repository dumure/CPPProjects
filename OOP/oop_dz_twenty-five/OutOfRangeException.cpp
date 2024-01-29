#include "OutOfRangeException.h"

char const* OutOfRangeException::what() const
{
	return "OutOfRangeException: Index is out of array!";
}

