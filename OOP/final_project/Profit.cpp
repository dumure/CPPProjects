#include "Profit.h"

Profit::Profit(const std::string& a_event_name, float a_cash)
{
	m_event_name = a_event_name;
	m_cash = a_cash;
	time_t now = time(0);
	m_creation_time = ctime(&now);
	m_creation_time = m_creation_time.substr(0, 24);
}

void Profit::show() // Показывает информацию о прибыли
{
	std::cout << "Прибыль | " << m_event_name << " | +" << m_cash << "AZN / +" << m_cash * 0.59 << "USD / +" << m_cash * 54 << "RUB / +" << m_cash * 0.54 << "EUR";
}
