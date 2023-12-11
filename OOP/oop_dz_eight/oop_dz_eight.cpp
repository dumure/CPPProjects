#include <iostream>
#include "IntArray.h"

std::ostream& operator<<(std::ostream& a_os, const IntArray& a_arr)
{
	a_os << "{ ";
	for (int i = 0; i < a_arr.m_size; i++)
	{
		a_os << a_arr.m_data[i];
		if (i != a_arr.m_size - 1)
		{
			a_os << ", ";
		}
	}
	a_os << " }\n";
	return a_os;
}

// я не понял какой именно делать cin поэтому сделал два варианта:

std::istream& operator>>(std::istream& a_is, IntArray& a_arr)
{
	for (int i = 0; i < a_arr.m_capacity; i++)
	{
		int value;
		a_is >> value;
		a_arr.append(value);
	}
	return a_is;
}

//std::istream& operator>>(std::istream& a_is, IntArray& a_arr)
//{
//	if (a_arr.m_capacity != a_arr.m_size)
//	{
//		int value;
//		a_is >> value;
//		a_arr.append(value);
//	}
//	return a_is;
//}

int main()
{
	IntArray int_array;
	std::cin >> int_array;
	std::cout << int_array;
}
