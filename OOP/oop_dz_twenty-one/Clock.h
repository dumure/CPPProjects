#pragma once
class Clock
{
	int m_hours;
	int m_minutes;
public:
	Clock(int a_hours, int a_minutes);
	Clock& operator++(int);
	Clock& operator++();
	Clock& operator--(int);
	Clock& operator--();
	bool operator<(const Clock& a_other);
	bool operator>(const Clock& a_other);
	bool operator<=(const Clock& a_other);
	bool operator>=(const Clock& a_other);
	bool operator==(const Clock& a_other);
	bool operator!=(const Clock& a_other);
	void set_hours(int a_hours);
	void set_minutes(int a_minutes);
	int get_hours();
	int get_minutes();
};

