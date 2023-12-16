#include <iostream>
#include "Dictionary.h"


int main()
{
    /*{
        while (true)
        {
            void* ptr = new int[6];
            delete[] ptr;
            std::cout << ptr;
        }
        return 0;
    }*/
    while (true)
    {
        Dictionary<std::string, int> container;
        container["key_one"] = 3;
        container["key_two"] = 4;
        container["key_three"] = 5;
        container["key_four"] = 6;
        container["key_five"] = 7;
        container["key_six"] = 8;
        //std::cout << container["key_five"] << '\n';
    }
}
