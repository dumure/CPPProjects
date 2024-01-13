#include "Device.h"

Device::Device(const std::string& a_name, long long a_serial_number) : m_name(a_name), m_serial_number(a_serial_number), m_power_state() {}

std::string Device::get_name()
{
	return m_name;
}

long long Device::get_serial_number()
{
	return m_serial_number;
}

bool Device::get_power_state()
{
	return m_power_state;
}

void Device::on()
{
	if (!m_power_state)
	{
		m_power_state = true;
		std::cout << "Turned " << m_name << " on." << '\n';
	}
}

void Device::off()
{
	if (m_power_state)
	{
		m_power_state = false;
		std::cout << "Turned " << m_name << " off." << '\n';
	}
}