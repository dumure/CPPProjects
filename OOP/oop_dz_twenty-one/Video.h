#pragma once
#include "File.h"
class Video : public File
{
	int m_duration;
public:
	Video(const std::string& a_extension, int a_size, int a_duration);
	int get_duration();
};

