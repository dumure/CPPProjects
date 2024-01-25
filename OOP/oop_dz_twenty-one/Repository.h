#pragma once
#include "Audio.h"
#include "Video.h"
#include "Image.h"
class Repository
{
	File** m_data;
	int m_capacity;
	int m_size;
	int m_local_size;
	void reallocate();
public:
	~Repository();
	Repository(const Repository& a_other);
	Repository(Repository&& a_other);
	Repository();
	void add(File* a_value);
	void remove(File* a_value);
	File* operator[](int index);
	Repository& operator=(const Repository& a_other);
	Repository& operator=(Repository&& a_other);
};

