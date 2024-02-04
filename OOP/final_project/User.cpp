#include "User.h"

User::User()
{
}

User::User(const std::string& a_login, const std::string& a_password) : m_login(a_login), m_password(StringEncryptor{}.encrypt(a_password)) { }

std::string User::get_login()
{
	return m_login;
}
std::string User::get_password()
{
	return m_password;
}

