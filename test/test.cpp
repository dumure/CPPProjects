#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file{ "text.txt" };

    if (file.is_open())
    {
        std::string str;
        file >> str;
        std::cout << str << '\n';
        file >> str;
        std::cout << str << '\n';
        file >> str;
        std::cout << str << '\n';

        file.close();
    }
}