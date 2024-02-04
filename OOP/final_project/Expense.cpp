#include "Expense.h"

Expense::Expense(const std::string& a_event_name, float a_cash)
{
	m_event_name = a_event_name;
	m_cash = a_cash;
	time_t now = time(0);
	m_creation_time = ctime(&now);
	m_creation_time = m_creation_time.substr(0, 24);
}

void Expense::show() // Показывает информацию о затрате
{
	std::cout << "Расход | " << m_event_name << " | " << m_cash << "AZN / " << m_cash * 0.59 << "USD / " << m_cash * 54 << "RUB / " << m_cash * 0.54 << "EUR";
}
