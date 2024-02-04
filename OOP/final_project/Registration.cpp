#include "Registration.h"

void Registration::sign_up() // ����������� ������ ������������
{
	MoneyGuard moneyguard_session;
	auto users = moneyguard_session.get_users_list();
	std::string login;
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
		flag = false;
		for (auto& i : users)
		{
			if (login == i.get_login())
			{
				std::cout << "������������ � ����� ������� ��� ����������! ��������� �������." << '\n';
				flag = true;
				break;
			}
		}
	}
	std::string password;
	std::string repeat_password;
	std::cout << "������� ������ (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
	std::cout << " --> ";
	std::cin >> password;
	system("cls");
	if (login == "0")
	{
		return;
	}
	while (true)
	{
		std::cout << "��������� ������ (������� 0 ���� ������ ������������ ������� ������ �����):" << '\n';
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
		std::cout << "������ �� ���������! ��������� �������." << '\n';
	}
	User new_user{ login, password };
	std::cout << "�� ������� ������� �������!" << '\n';
	moneyguard_session.start(new_user);
	moneyguard_session.add_user();
}