#pragma once
#include "Audio.h"
#include "Video.h"
#include "Image.h"
#include "LinkedList.h"
class RepositoryList
{
	LinkedList<File*> m_list;
	int m_size;
public:
	~RepositoryList();
	RepositoryList();
	LinkedList<File*>::Node* add(File* a_file);
	void remove(LinkedList<File*>::Node* a_file_node);
	int get_size();
	File* operator[](int index);
};

