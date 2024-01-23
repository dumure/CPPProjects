#include <iostream>
#include "SharedPtr.h"

int main()
{
    SharedPtr<int> ptr{nullptr};

    std::cout << ptr.use_count() << '\n';

    {
        SharedPtr<int> ptr2{ptr};
        std::cout << ptr.use_count() << '\n';
        std::cout << ptr2.use_count() << '\n';
    }

    std::cout << ptr.use_count();
}
