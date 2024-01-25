#include "DateTime.h"

DateTime::DateTime()
{
	m_years = 1900;
	m_months = 1;
	m_mdays = 1;
	m_ydays = 1;
	m_wday = 1;
	m_hours = 12;
	m_minutes = 0;
	m_seconds = 1;
}

DateTime DateTime::get_now()
{
	DateTime result;
	auto time_in_sec = time(0);
	auto current_time = localtime(&time_in_sec);
	result.m_years = current_time->tm_year;
	result.m_months = current_time->tm_mon;
	result.m_mdays = current_time->tm_mday;
	result.m_ydays = current_time->tm_yday;
	result.m_hours = current_time->tm_hour;
	result.m_minutes = current_time->tm_min;
	result.m_seconds = current_time->tm_sec;
	return result;
}

bool DateTime::is_current_year_leap()
{
	if (m_years % 100 == 0)
	{
		if (m_years % 400 == 0)
		{
			return true;
		}
		return false;
	}
	else
	{
		return m_years % 4 == 0;
	}
}

int DateTime::get_year()
{
	return m_years;
}

int DateTime::get_month()
{
	return m_months;
}

int DateTime::get_mday()
{
	return m_mdays;
}

int DateTime::get_yday()
{
	return m_ydays;
}

int DateTime::get_weeks_day()
{
	return m_wday;
}

int DateTime::get_hours()
{
	return m_hours;
}

int DateTime::get_minutes()
{
	return m_minutes;
}

int DateTime::get_seconds()
{
	return m_seconds;
}

bool DateTime::operator<(const DateTime& a_other)
{
	if (m_years != a_other.m_years)
	{
		return m_years < a_other.m_years;
	}
	else
	{
		if (m_months != a_other.m_months)
		{
			return m_months < a_other.m_months;
		}
		else
		{
			if (m_mdays != a_other.m_mdays)
			{
				return m_mdays < a_other.m_mdays;
			}
			else
			{
				if (m_hours != a_other.m_hours)
				{
					return m_hours < a_other.m_hours;
				}
				else
				{
					if (m_minutes != a_other.m_minutes)
					{
						return m_minutes < a_other.m_minutes;
					}
					else
					{
						return m_seconds < a_other.m_seconds;
					}
				}
			}
		}
	}
}

bool DateTime::operator>(const DateTime& a_other)
{
	if (m_years != a_other.m_years)
	{
		return m_years > a_other.m_years;
	}
	else
	{
		if (m_months != a_other.m_months)
		{
			return m_months > a_other.m_months;
		}
		else
		{
			if (m_mdays != a_other.m_mdays)
			{
				return m_mdays > a_other.m_mdays;
			}
			else
			{
				if (m_hours != a_other.m_hours)
				{
					return m_hours > a_other.m_hours;
				}
				else
				{
					if (m_minutes != a_other.m_minutes)
					{
						return m_minutes > a_other.m_minutes;
					}
					else
					{
						return m_seconds > a_other.m_seconds;
					}
				}
			}
		}
	}
}

bool DateTime::operator<=(const DateTime& a_other)
{
	if (m_years != a_other.m_years)
	{
		return m_years <= a_other.m_years;
	}
	else
	{
		if (m_months != a_other.m_months)
		{
			return m_months <= a_other.m_months;
		}
		else
		{
			if (m_mdays != a_other.m_mdays)
			{
				return m_mdays <= a_other.m_mdays;
			}
			else
			{
				if (m_hours != a_other.m_hours)
				{
					return m_hours <= a_other.m_hours;
				}
				else
				{
					if (m_minutes != a_other.m_minutes)
					{
						return m_minutes <= a_other.m_minutes;
					}
					else
					{
						return m_seconds <= a_other.m_seconds;
					}
				}
			}
		}
	}
}

bool DateTime::operator>=(const DateTime& a_other)
{
	if (m_years != a_other.m_years)
	{
		return m_years >= a_other.m_years;
	}
	else
	{
		if (m_months != a_other.m_months)
		{
			return m_months >= a_other.m_months;
		}
		else
		{
			if (m_mdays != a_other.m_mdays)
			{
				return m_mdays >= a_other.m_mdays;
			}
			else
			{
				if (m_hours != a_other.m_hours)
				{
					return m_hours >= a_other.m_hours;
				}
				else
				{
					if (m_minutes != a_other.m_minutes)
					{
						return m_minutes >= a_other.m_minutes;
					}
					else
					{
						return m_seconds >= a_other.m_seconds;
					}
				}
			}
		}
	}
}

bool DateTime::operator==(const DateTime& a_other)
{
	return (m_years == a_other.m_years && m_months == a_other.m_months && m_mdays == a_other.m_mdays && m_hours == a_other.m_hours && m_minutes == a_other.m_minutes && m_seconds == a_other.m_seconds);
}

bool DateTime::operator!=(const DateTime& a_other)
{
	return (m_years != a_other.m_years && m_months != a_other.m_months && m_mdays != a_other.m_mdays && m_hours != a_other.m_hours && m_minutes != a_other.m_minutes && m_seconds != a_other.m_seconds);
}
