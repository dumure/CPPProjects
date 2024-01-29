#include "LimitException.h"

char const* LimitException::what() const
{
	return "LimitException: Don't exceed the array limit!";
}
