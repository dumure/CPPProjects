#pragma once
#include "Laptop.h"
class GamingLaptop : public Laptop
{
	bool m_overclock_state;
	bool m_extreme_cooling_state;
	bool m_network_priority_state;
	void toggle_overclock();
public:
	GamingLaptop(const std::string& a_name, long long a_serial_number, const std::string& a_manufacturer, bool a_overclock_state);
	void toggle_extreme_cooling();
	void toggle_network_priority();
};

