#pragma once
#include "File.h"
class Audio : public File
{
	int m_duration;
	int m_bitrate;
	std::string m_performer;
	std::string m_track_name;
public:
	Audio(const std::string& a_extension, int a_size, int a_duration, int a_bitrate, const std::string& a_performer, const std::string& a_track_name);
	int get_duration();
	int get_bitrate();
	std::string& get_performer();
	std::string& get_track_name();
};

