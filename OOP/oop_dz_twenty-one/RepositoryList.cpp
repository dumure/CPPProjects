#include "RepositoryList.h"

RepositoryList::~RepositoryList()
{
	for (auto& ptr : m_list)
	{
		delete ptr;
	}
}

RepositoryList::RepositoryList()
{
	m_size = m_list.m_size;
}

LinkedList<File*>::Node* RepositoryList::add(File* a_file)
{
	++m_size;
	return m_list.push_back(a_file);
}

void RepositoryList::remove(LinkedList<File*>::Node* a_file_node)
{
	if (m_size == 1)
	{
		delete a_file_node->m_value;
		delete a_file_node;
		m_list.m_head = m_list.m_tail = nullptr;
		--m_size;
		--m_list.m_size;
	}
	else if (a_file_node == m_list.m_head)
	{
		m_list.m_head = m_list.m_head->m_next;
		delete m_list.m_head->m_prev->m_value;
		delete m_list.m_head->m_prev;
		m_list.m_head->m_prev = nullptr;
		--m_size;
		--m_list.m_size;
	}
	else if (a_file_node == m_list.m_tail)
	{
		m_list.m_tail = m_list.m_tail->m_prev;
		delete m_list.m_tail->m_next->m_value;
		delete m_list.m_tail->m_next;
		m_list.m_tail->m_next = nullptr;
		--m_size;
		--m_list.m_size;
	}
	else
	{
		a_file_node->m_prev->m_next = a_file_node->m_next;
		a_file_node->m_next->m_prev = a_file_node->m_prev;
		delete m_list.m_tail->m_value;
		delete m_list.m_tail;
		--m_size;
		--m_list.m_size;
	}
}

int RepositoryList::get_size()
{
	return m_size;
}

File* RepositoryList::operator[](int index)
{
	if (index > -1 && index < m_size)
	{
		auto ptr = m_list.begin();
		return *(ptr + index);
	}
	return nullptr;
}
