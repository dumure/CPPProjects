#include "Clock.h"

Clock::Clock(int a_hours, int a_minutes)
{
	m_hours = a_hours;
	m_minutes = a_minutes;
}

Clock& Clock::operator++(int)
{
	Clock result = *this;

	m_minutes++;

	if (m_minutes == 60)
	{
		m_minutes = 0;
		m_hours++;
		if (m_hours == 24)
		{
			m_hours = 0;
		}
	}

	return result;
}

Clock& Clock::operator++()
{
	m_minutes++;

	if (m_minutes == 60)
	{
		m_minutes = 0;
		m_hours++;
		if (m_hours == 24)
		{
			m_hours = 0;
		}
	}

	return *this;
}

Clock& Clock::operator--(int)
{
	Clock result = *this;

	m_minutes--;

	if (m_minutes == -1)
	{
		m_minutes = 59;
		m_hours--;
		if (m_hours == -1)
		{
			m_hours = 23;
		}
	}

	return result;
}

Clock& Clock::operator--()
{
	m_minutes--;

	if (m_minutes == -1)
	{
		m_minutes = 59;
		m_hours--;
		if (m_hours == -1)
		{
			m_hours = 23;
		}
	}

	return *this;
}

bool Clock::operator<(const Clock& a_other)
{
	if (m_hours != a_other.m_hours)
	{
		return m_hours < a_other.m_hours;
	}
	else
	{
		return m_minutes < a_other.m_minutes;
	}
}

bool Clock::operator>(const Clock& a_other)
{
	if (m_hours != a_other.m_hours)
	{
		return m_hours > a_other.m_hours;
	}
	else
	{
		return m_minutes > a_other.m_minutes;
	}
}

bool Clock::operator<=(const Clock& a_other)
{
	if (m_hours != a_other.m_hours)
	{
		return m_hours <= a_other.m_hours;
	}
	else
	{
		return m_minutes <= a_other.m_minutes;
	}
}

bool Clock::operator>=(const Clock& a_other)
{
	if (m_hours != a_other.m_hours)
	{
		return m_hours >= a_other.m_hours;
	}
	else
	{
		return m_minutes >= a_other.m_minutes;
	}
}

bool Clock::operator==(const Clock& a_other)
{
	return (m_hours == a_other.m_hours && m_minutes == a_other.m_minutes);
}

bool Clock::operator!=(const Clock& a_other)
{
	return (m_hours != a_other.m_hours && m_minutes != a_other.m_minutes);
}

void Clock::set_hours(int a_hours)
{
	if (a_hours >= 0 && a_hours < 24)
	{
		m_hours = a_hours;
	}
}

void Clock::set_minutes(int a_minutes)
{
	if (a_minutes >= 0 && a_minutes < 60)
	{
		m_minutes = a_minutes;
	}
}

int Clock::get_hours()
{
	return m_hours;
}

int Clock::get_minutes()
{
	return m_minutes;
}