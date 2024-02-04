#include "Registration.h"

void Registration::sign_up() // Регистрация нового пользователя
{
	MoneyGuard moneyguard_session;
	auto users = moneyguard_session.get_users_list();
	std::string login;
	bool flag = true;
	while (flag)
	{
		std::cout << "Введите логин (введите 0 если хотите сымитировать нажатие кнопки назад):" << '\n';
		std::cout << " --> ";
		std::cin >> login;
		std::string lower_login;
		for (int i = 0; i < login.size(); i++)
		{
			lower_login.push_back(tolower(login.at(i)));
		}
		login = std::move(lower_login);
		system("cls");
		if (login == "0")
		{
			return;
		}
		flag = false;
		for (auto& i : users)
		{
			if (login == i.get_login())
			{
				std::cout << "Пользователь с таким логином уже существует! Повторите попытку." << '\n';
				flag = true;
				break;
			}
		}
	}
	std::string password;
	std::string repeat_password;
	std::cout << "Введите пароль (введите 0 если хотите сымитировать нажатие кнопки назад):" << '\n';
	std::cout << " --> ";
	std::cin >> password;
	system("cls");
	if (login == "0")
	{
		return;
	}
	while (true)
	{
		std::cout << "Повторите пароль (введите 0 если хотите сымитировать нажатие кнопки назад):" << '\n';
		std::cout << " --> ";
		std::cin >> repeat_password;
		system("cls");
		if (login == "0")
		{
			return;
		}
		if (repeat_password == password)
		{
			break;
		}
		std::cout << "Пароли не совпадают! Повторите попытку." << '\n';
	}
	User new_user{ login, password };
	std::cout << "Вы успешно создали аккаунт!" << '\n';
	moneyguard_session.start(new_user);
	moneyguard_session.add_user();
}