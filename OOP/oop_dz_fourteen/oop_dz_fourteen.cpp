#include <iostream>
#include "Stack.h"

int main()
{
    Stack<std::string> stack;
    stack.push("Hello ");
    stack.push("C++ and ");
    stack.push("Python");
    std::cout << stack;
    std::cout << stack.size() << '\n';
    std::cout << sizeof(std::string) << '\n';
}
