#include <iostream>
#include "Authorization.h"

int main()
{
    // ���� �����
    setlocale(0, "ru");
    std::cout << "������������ ��� � ���������� MoneyGuard!" << '\n';
    bool flag = true;
    while (flag)
    {
        std::cout << "A - �����������;" << '\n';
        std::cout << "B - �����������;" << '\n';
        std::cout << "C - �����." << '\n';
        std::cout << " --> ";
        char choice;
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case 'A':
        case 'a':
            {
                Registration registration;
                registration.sign_up();
                break;
            }
        case 'B':
        case 'b':
            {
                Authorization authorization;
                authorization.sign_in();
                break;
            }
        case 'C':
        case 'c':
            {
                flag = false;
                break;
            }
        default:
            {
                std::cout << "������������ ����! ���������� ������." << '\n';
                break;
            }
        }
    }
}
