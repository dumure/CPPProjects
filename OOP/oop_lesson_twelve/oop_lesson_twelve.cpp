#include <iostream>

void foo(int arg)
{
	std::cout << arg << " - int\n";
}

void foo(float arg)
{
	std::cout << arg << " - float\n";
}

void foo(char arg)
{
	std::cout << arg << " - char\n";
}

template<typename... Args>
void print_x2(Args&&... args)
{
	((foo(args)), ...);
}

int main()
{
	print_x2(1, '2', 3.f);
}
