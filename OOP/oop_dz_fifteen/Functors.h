#pragma once
template<typename T>
class None
{
public:
	bool operator()(T a, T b)
	{
		return false;
	}
};

template<typename T>
class Greater
{
public:
	bool operator()(T a, T b)
	{
		return a > b;
	}
};

template<typename T>
class Less
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

