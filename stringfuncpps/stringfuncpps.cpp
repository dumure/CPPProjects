#include <iostream>
#include "Array.h"

int main()
{
	Str<char> text = str_create<char>();

	str_append(text, "dsfsdifjdaofjdsifdsfjdsifds");
	std::cout << text.data;


	str_destroy(text);
}
