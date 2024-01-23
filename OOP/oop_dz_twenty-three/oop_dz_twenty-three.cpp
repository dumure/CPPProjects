#include <iostream>
#include "UniquePtr.h"

int main()
{
    //while (true)
    {
        UniquePtr<int[]> arr = new int[5]{1,2,3,4,5};
        std::cout << arr[0] << '\n';
    }
}
