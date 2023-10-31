#include "User.h"
#include <iostream>

int GlobalValue = 42;

User* createUser()
{
	return new User;
}

void destroyUser(User* user)
{
	delete user;
}

void showGlobalValue_()
{
	std::cout << &GlobalValue;
}