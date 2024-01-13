#pragma once
#include "Device.h"
class Smartphone : public Device
{
	std::string m_manufacturer;
public:
	Smartphone(const std::string& a_name, long long a_serial_number, const std::string& a_manufacturer);
	void take_photo();
	void record_video();
	void set_alarm();
};

