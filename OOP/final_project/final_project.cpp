#include <iostream>
#include "Authorization.h"

int main()
{
    // Меню входа
    setlocale(0, "ru");
    std::cout << "Приветствуем вас в приложении MoneyGuard!" << '\n';
    bool flag = true;
    while (flag)
    {
        std::cout << "A - Регистрация;" << '\n';
        std::cout << "B - Авторизация;" << '\n';
        std::cout << "C - Выход." << '\n';
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
                std::cout << "Неправильный ввод! Попробуйте заново." << '\n';
                break;
            }
        }
    }
}
