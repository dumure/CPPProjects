#pragma once
#include "Clock.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class DateTime
{
	int m_years;
	int m_months;
	int m_mdays;
	int m_ydays;
	int m_wday;
	int m_hours;
	int m_minutes;
	int m_seconds;
public:
	DateTime();
	static DateTime get_now();
	bool is_current_year_leap();
	int get_year();
	int get_month();
	int get_mday();
	int get_yday();
	int get_weeks_day();
	int get_hours();
	int get_minutes();
	int get_seconds();
	bool operator<(const DateTime& a_other);
	bool operator>(const DateTime& a_other);
	bool operator<=(const DateTime& a_other);
	bool operator>=(const DateTime& a_other);
	bool operator==(const DateTime& a_other);
	bool operator!=(const DateTime& a_other);
};

