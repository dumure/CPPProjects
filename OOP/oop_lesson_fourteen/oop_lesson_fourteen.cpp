#include <iostream>

template<typename T>
struct is_class
{
    constexpr static bool value = true;
};

template<typename T>
struct is_class<T*>
{
    constexpr static bool value = false;
};
template<typename T>
struct is_class<T&>
{
    constexpr static bool value = false;
};
template<>
struct is_class<int>
{
    constexpr static bool value = false;
};

int main()
{
    std::cout << std::boolalpha << is_class<int****>::value;
}