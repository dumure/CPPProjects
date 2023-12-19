#pragma once

template <typename T>
struct is_primitive
{
	constexpr static bool value = false;
}; 

template<>
struct is_primitive<int>
{
	constexpr static bool value = true;
};

template<>
struct is_primitive<char>
{
	constexpr static bool value = true;
};

template<>
struct is_primitive<bool>
{
	constexpr static bool value = true;
};

template<>
struct is_primitive<short>
{
	constexpr static bool value = true;
};
