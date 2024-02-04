#pragma once
#include <iostream>
#include "StringEncryptor.h"
#include "Category.h"
class User
{
	friend class MoneyGuard;
	std::string m_login;
	std::string m_password;
	std::vector<Category> m_categories;
public:
	User();
	User(const std::string& a_login, const std::string& a_password);
	std::string get_login();
	std::string get_password();
};
