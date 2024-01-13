#pragma once
#include <iostream>
class Device
{
	std::string m_name;
	long long m_serial_number;
	bool m_power_state;
protected:
	Device(const std::string& a_name, long long a_serial_number);
public:
	std::string get_name();
	long long get_serial_number();
	bool get_power_state();
	void on();
	void off();
};

