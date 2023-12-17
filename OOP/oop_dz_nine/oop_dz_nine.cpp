#include <iostream>
#include "Greater.h"
#include "Less.h"
#include "SortedRandomArray.h"

std::ostream& operator<<(std::ostream& a_os, SortedRandomArray& a_sra)
{
	a_os << "{ ";
	for (int i = 0; i < a_sra.m_size; i++)
	{
		a_os << a_sra.m_data[i];
		if (i != a_sra.m_size - 1)
		{
			a_os << ", ";
		}
	}
	a_os << " }\n";
	return a_os;
}

int main()
{
	Greater greater;
	Less less;
	SortedRandomArray sra{ 5 };
	sra.sort(less);
	std::cout << sra;
	sra.sort(greater);
	std::cout << sra;
}

