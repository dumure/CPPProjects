#pragma once
#include "Device.h"
class Laptop : public Device
{
	std::string m_manufacturer;
	bool m_touchpad_state;
	bool m_is_browser_opened;
public:
	Laptop(const std::string& a_name, long long a_serial_number, const std::string& a_manufacturer);
	void open_browser();
	void close_browser();
	void toggle_touchpad();
};

