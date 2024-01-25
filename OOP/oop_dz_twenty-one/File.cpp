#include "File.h"

File::File(const std::string& a_extension, int a_size) : m_extension(a_extension), m_size(a_size), m_creation_date(DateTime::get_now()) { }

File::~File() { }

std::string& File::get_extension()
{
	return m_extension;
}

int File::get_size()
{
	return m_size;
}

DateTime& File::get_creation_date()
{
	return m_creation_date;
}