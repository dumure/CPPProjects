#include "Smartphone.h"

Smartphone::Smartphone(const std::string& a_name, long long a_serial_number, const std::string& a_manufacturer) : Device(a_name, a_serial_number), m_manufacturer(a_manufacturer) {}

void Smartphone::take_photo()
{
	if (get_power_state())
	{
		std::cout << "Taked a photo.";
	}
}

void Smartphone::record_video()
{
	if (get_power_state())
	{
		std::cout << "Recorded a video.";
	}
}

void Smartphone::set_alarm()
{
	if (get_power_state())
	{
		std::cout << "Setted alarm.";
	}
}