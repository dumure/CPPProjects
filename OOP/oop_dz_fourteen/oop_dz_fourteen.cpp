#include <iostream>
#include <string>
#include "Stack.h"

bool is_brackets_correct(std::string a_string)
{
    Stack<char> stack;
    for (int i = 0; i < a_string.size(); i++)
    {
        if (a_string[i] == '(' || a_string[i] == '[' || a_string[i] == '{')
        {
            stack.push(a_string[i]);
        }
        if (!a_string.empty())
        {
            if (stack.peek() == '(')
            {
                if (a_string[i] == ')')
                {
                    stack.pop();
                }
            }
            else if (stack.peek() == '[')
            {
                if (a_string[i] == ']')
                {
                    stack.pop();
                }
            }
            else if (stack.peek() == '{')
            {
                if (a_string[i] == '}')
                {
                    stack.pop();
                }
            }
        }
    }
    return stack.empty();
}

int main()
{
    bool check = is_brackets_correct("(1{2[test}])");
    if (check)
    {
        std::cout << "OK" << '\n';
    }
    else
    {
        std::cout << "NOT OK" << '\n';
    }
}
