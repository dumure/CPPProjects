#include <iostream>
#include "Greater.h"
#include "Less.h"
#include "SortedRandomArray.h"

int main()
{
	Greater greater;
	std::cout << std::boolalpha << greater(5, 4);
}

