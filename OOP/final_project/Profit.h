#pragma once
#include "Event.h"
class Profit : public Event
{
public:
	Profit(const std::string& a_event_name, float a_cash);
	virtual void show() override;
};

