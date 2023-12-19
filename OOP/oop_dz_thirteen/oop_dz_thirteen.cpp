#include <iostream>
#include "is_primitive.h"
#include "is_ref.h"

int main()
{
    if (is_primitive<int&>::value)
    {
        std::cout << "This type is primitive :)" << '\n';
    }
    else if (is_ref<int&>::value)
    {
        std::cout << "This type isn't primitive but it's ref type :|" << '\n';
    }
    else
    {
        std::cout << "This type isn't primitive and ref type :(" << '\n';
    }
}
