#include "Video.h"

Video::Video(const std::string& a_extension, int a_size, int a_duration) : File(a_extension, a_size), m_duration(a_duration) { }