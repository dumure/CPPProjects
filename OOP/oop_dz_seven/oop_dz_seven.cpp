#include <iostream>
#include "IntArray.h"

int main()
{
    IntArray a1;
    a1.append(1);
    a1.append(2);
    IntArray a2;
    a2.append(3);
    a2.append(4);
    IntArray a3;
    a3 = a1 + a2;
    for (int i = 0; i < a3.get_size(); i++)
    {
        std::cout << a3.get_data(i) << '\n';
    }
}
