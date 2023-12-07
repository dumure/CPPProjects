#include <iostream>
#include "IntArray.h"

int main()
{
    IntArray arr;
    arr.append(4);
    arr.append(2);
    arr.append(5);
    arr.append(3);
    arr.prepend(5);
    std::cout << "{ ";
    for (int i = 0; i < arr.get_size(); i++)
    {
        std::cout << arr.get_data(i) << ", ";
    }
    std::cout << "\b\b }\n";
    arr.bubble_sort();
    std::cout << "{ ";
    for (int i = 0; i < arr.get_size(); i++)
    {
        std::cout << arr.get_data(i) << ", ";
    }
    std::cout << "\b\b }\n";
}
