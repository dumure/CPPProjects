#include "GamingLaptop.h"

GamingLaptop::GamingLaptop(const std::string& a_name, long long a_serial_number, const std::string& a_manufacturer, bool a_overclock_state) : Laptop(a_name, a_serial_number, a_manufacturer), m_overclock_state(a_overclock_state), m_extreme_cooling_state(), m_network_priority_state() {}

void GamingLaptop::toggle_overclock()
{
	if (get_power_state())
	{
		if (!m_overclock_state)
		{
			m_overclock_state = true;
			std::cout << "Overclock turned on." << '\n';
		}
		else
		{
			m_overclock_state = false;
			std::cout << "Overclock turned off." << '\n';
		}
	}
}

void GamingLaptop::toggle_extreme_cooling()
{
	if (get_power_state())
	{
		if (!m_extreme_cooling_state)
		{
			m_extreme_cooling_state = true;
			std::cout << "Extreme cooling turned on." << '\n';
		}
		else
		{
			m_extreme_cooling_state = false;
			std::cout << "Extreme cooling turned off." << '\n';
		}
	}
}

void GamingLaptop::toggle_network_priority()
{
	if (get_power_state())
	{
		if (!m_network_priority_state)
		{
			m_network_priority_state = true;
			std::cout << "Network priority turned on." << '\n';
		}
		else
		{
			m_network_priority_state = false;
			std::cout << "Network priority turned off." << '\n';
		}
	}
}