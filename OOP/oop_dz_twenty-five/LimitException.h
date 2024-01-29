#pragma once
#include "FixedArrayExceptions.h"
class LimitException : public FixedArrayExceptions
{
public:
	virtual char const* what() const override;
};

