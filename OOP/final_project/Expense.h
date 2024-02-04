#pragma once
#include "Profit.h"
class Expense : public Event
{
public:
	Expense(const std::string& a_event_name, float a_cash);
	virtual void show() override;
};


