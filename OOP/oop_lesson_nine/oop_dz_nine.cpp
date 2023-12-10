#include <iostream>

class Greater
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	Greater is_great;
	std::cout << std::boolalpha << is_great(5, 4);
}

