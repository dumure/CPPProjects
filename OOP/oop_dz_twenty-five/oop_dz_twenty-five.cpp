#include <iostream>
#include "FixedArray.h"
#include "FixedArrayExceptions.h"

int main()
{
	//while (true)
	{
		try
		{
			FixedArray<int, 5> arr;
			arr.push_back(1);
			arr.push_back(2);
			arr.push_back(3);
			arr.push_back(4);
			arr.push_back(5);
			//arr.push_back(6);
			std::cout << arr[-1];
		}
		catch (const FixedArrayExceptions& ex)
		{
			std::cout << ex.what() << '\n';
		}
	}
}
