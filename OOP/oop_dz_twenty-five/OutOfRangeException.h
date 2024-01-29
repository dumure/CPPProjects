#pragma once
#include "FixedArrayExceptions.h"
class OutOfRangeException : public FixedArrayExceptions
{
public:
	virtual char const* what() const override;
};

