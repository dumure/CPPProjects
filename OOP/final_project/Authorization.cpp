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
		std::cout << "������� ����� (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
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
			std::cout << "������������ � ����� ������� �� ���������������! ��������� ������� ���� ���������������� ���������� �����." << '\n';
		}
	}
	while (true)
	{
		std::string password;
		std::cout << "������� ������ (������� 0 ���� ������ ������������ ������� ������ �����): " << '\n';
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
		std::cout << "������������ ������! ��������� �������." << '\n';
	}
	std::cout << "�� ������� ����� � �������!" << '\n';
	moneyguard_session.start(user);
	moneyguard_session.update_user();
}
