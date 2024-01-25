#pragma once
#include "Audio.h"
#include "Video.h"
#include "Image.h"
#include "Array.h"
class RepositoryArray
{
	Array<File*> m_arr;
	int m_size;
	int m_local_size;
	int m_capacity;
public:
	~RepositoryArray();
	RepositoryArray();
	void add(File* a_file);
	void remove(File* a_file);
	int get_size();
	int get_capacity();
	File* operator[](int index);
};

