#include <iostream>

template<typename T> class Test
{

};

int main()
{
	int n;
	std::cin >> n;
	int d1 = n;
	int d2 = 1;
	int sum = 0;
	while (d1 <= std::pow(n, 2) - n + 1)
	{
		sum += d1;
		d1 += (n - 1);
	}
	while (d2 <= std::pow(n, 2))
	{
		sum += d2;
		d2 += (n + 1);
	}
	if (n % 2 != 0)
	{
		sum -= ((1 + std::pow(n, 2)) / 2);
	}
	std::cout << sum;
}