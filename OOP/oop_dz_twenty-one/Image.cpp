#include "Image.h"

Image::Image(const std::string& a_extension, int a_size, const std::string& a_resolution) : File(a_extension, a_size), m_resolution(a_resolution) { }

std::string& Image::get_resolution()
{
	return m_resolution;
}
