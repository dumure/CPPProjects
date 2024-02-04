#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
class Event
{
	friend class MoneyGuard;
protected:
	std::string m_event_name;
	std::string m_creation_time;
	float m_cash;
public:
	virtual ~Event();
	virtual void show() = 0;
};

