#include "Laptop.h"

Laptop::Laptop(const std::string& a_name, long long a_serial_number, const std::string& a_manufacturer) : Device(a_name, a_serial_number), m_manufacturer(a_manufacturer), m_touchpad_state(), m_is_browser_opened() {}

void Laptop::open_browser()
{
	if (get_power_state() && !m_is_browser_opened)
	{
		{
			m_is_browser_opened = true;
			std::cout << "Browser opened." << '\n';
		}
	}
}

void Laptop::close_browser()
{
	if (get_power_state() && m_is_browser_opened)
	{
		{
			m_is_browser_opened = false;
			std::cout << "Browser closed." << '\n';
		}
	}
}

void Laptop::toggle_touchpad()
{
	if (get_power_state())
	{
		if (!m_touchpad_state)
		{
			m_touchpad_state = true;
			std::cout << "Touchpad turned on." << '\n';
		}
		else
		{
			m_touchpad_state = false;
			std::cout << "Touchpad turned off." << '\n';
		}
	}
}