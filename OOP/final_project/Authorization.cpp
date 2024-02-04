#include "Authorization.h"

void Authorization::sign_in()
{
	MoneyGuard moneyguard_session;
	auto users = moneyguard_session.get_users_list();
	std::string login;
	User user;
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
		flag = true;
		for (auto& i : users)
		{
			if (login == i.get_login())
			{
				user = i;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			std::cout << "Пользователь с таким логином не зарегистрирован! Повторите попытку либо зарегистируйтесь вернувшись назад." << '\n';
		}
	}
	while (true)
	{
		std::string password;
		std::cout << "Введите пароль (введите 0 если хотите сымитировать нажатие кнопки назад): " << '\n';
		std::cin >> password;
		password = StringEncryptor{}.encrypt(password);
		system("cls");
		if (login == "0")
		{
			return;
		}
		if (password == user.get_password())
		{
			break;
		}
		std::cout << "Неправильный пароль! Повторите попытку." << '\n';
	}
	std::cout << "Вы успешно вошли в аккаунт!" << '\n';
	moneyguard_session.start(user);
	moneyguard_session.update_user();
}
