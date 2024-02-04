#pragma once
#include <iostream>
#include <vector>
#include "Expense.h"
class Category
{
	friend class MoneyGuard;
	std::string m_category_name;
	std::vector<Event*> m_events;
public:
	Category(const std::string& a_category_name);
	Category();
};

