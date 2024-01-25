#pragma once
#include "DateTime.h"
class File
{
	std::string m_extension;
	int m_size;
	DateTime m_creation_date;
protected:
	File(const std::string& a_extension, int a_size);
public:
	virtual ~File();
	std::string& get_extension();
	int get_size();
	DateTime& get_creation_date();
};

