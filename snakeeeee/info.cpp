#include "Header.h"

void info()
{
    system("cls");
    std::cout << "******************************************\n";
    std::cout << "*                                        *\n";
    std::cout << "*            Info | Get ready            *\n";
    std::cout << "*                                        *\n";
    std::cout << "******************************************\n";
    std::cout << "*                                        *\n";
    std::cout << "*       Space - skip this window         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*        @ - apple ( score + 1 )         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*         & - pear ( score - 1 )         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*         X - wall ( game over )         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*          O - snake ( player )          *\n";
    std::cout << "*                                        *\n";
    std::cout << "*      0 - mirrored snake ( enemy )      *\n";
    std::cout << "*                                        *\n";
    std::cout << "*            a - acceleration            *\n";
    std::cout << "*                                        *\n";
    std::cout << "*            d - deceleration            *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "******************************************";
    char key = 0;
    for (int i = 0; i < 32; i++)
    {
        if (_kbhit())
        {
            key = _getch();
        }
        if (key == 32)
        {
            break;
        }
        Sleep(250);
    }
}