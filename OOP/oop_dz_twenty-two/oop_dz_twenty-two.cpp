#include <iostream>
#include <list>
#include <set>

int main()
{
	auto pow = [](int a, int b)
	{
		float result = a;
		int a_copy = a;
		int b_copy = b;
		if (b == 0)
		{
			return 1.f;
		}
		for (int i = 0; i < (b < 0 ? -b : b) - 1; i++)
		{
			result = 0;
			for (int i = 0; i < (a < 0 ? -a : a); i++)
			{
				result += a_copy;
			}
			a_copy = result;
		}
		if (a < 0 && b % 2 != 0)
		{
			result = -result;
		}
		if (b < 0)
		{
			return 1 / result;
		}
		return result;
	};

	std::cout << pow(2, -2);
}

