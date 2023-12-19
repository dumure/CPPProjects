#pragma once

template<typename T>
struct is_ref
{
	constexpr static bool value = false;
};

template<typename T>
struct is_ref<T&>
{
	constexpr static bool value = true;
};

template<typename T>
struct is_ref<T&&>
{
	constexpr static bool value = true;
};

