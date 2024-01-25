#pragma once
#include "File.h"
class Image : public File
{
	std::string m_resolution;
public:
	Image(const std::string& a_extension, int a_size, const std::string& a_resolution);
	std::string& get_resolution();
};

