#include <iostream>
#include <random>

int main()
{
    std::default_random_engine engine;
    std::uniform_int_distribution<int> range(10, 99);

    std::cout << range(engine);
}

