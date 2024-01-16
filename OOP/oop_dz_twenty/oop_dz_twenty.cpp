#include <iostream>
#include "LinkedList.h"

int main() 
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	auto iterator = list.begin();
	std::cout << *(iterator + 10);
}