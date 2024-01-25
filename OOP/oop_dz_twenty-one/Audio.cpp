#include "Audio.h"

Audio::Audio(const std::string& a_extension, int a_size, int a_duration, int a_bitrate, const std::string& a_performer, const std::string& a_track_name) : File(a_extension, a_size), m_duration(a_duration), m_bitrate(a_bitrate), m_performer(a_performer), m_track_name(a_track_name) { }

int Audio::get_duration()
{
	return m_duration;
}

int Audio::get_bitrate()
{
	return m_bitrate;
}

std::string& Audio::get_performer()
{
	return m_performer;
}

std::string& Audio::get_track_name()
{
	return m_track_name;
}