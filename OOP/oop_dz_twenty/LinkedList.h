#pragma once
template<typename T>
class LinkedList
{
public:
	class Node
	{
	public:
		Node(const T& a_value) : m_value(a_value), m_next() { }
		T m_value;
		Node* m_next;
		Node* m_prev;
	};

	class Iterator
	{
		Node* m_ptr;
		Node* m_head;
		Node* m_tail;
	public:
		Iterator(Node* a_ptr) : m_ptr(a_ptr) 
		{
			m_head = m_ptr;
			Node* l_current = m_head;
			while (l_current->m_next != nullptr)
			{
				l_current = l_current->m_next;
			}
			m_tail = l_current;
		}

		T& operator*()
		{
			return m_ptr->m_value;
		}

		Iterator& operator++(int)
		{
			if (m_ptr == nullptr)
			{
				return *this;
			}

			auto l_ptr = *this;

			m_ptr = m_ptr->m_next;

			return l_ptr;
		}

		Iterator& operator++()
		{
			if (m_ptr == nullptr)
			{
				return *this;
			}

			m_ptr = m_ptr->m_next;

			return *this;
		}

		Iterator& operator--(int)
		{
			if (m_ptr == nullptr)
			{
				return *this;
			}

			auto l_ptr = *this;

			m_ptr = m_ptr->m_prev;

			return l_ptr;
		}

		Iterator& operator--()
		{
			if (m_ptr == nullptr)
			{
				return *this;
			}

			m_ptr = m_ptr->m_prev;

			return *this;
		}

		Iterator operator-(int a_number)
		{
			for (int i = a_number; i > 0 && m_ptr != nullptr; i--)
			{
				m_ptr = m_ptr->m_prev;
			}
			if (m_ptr == nullptr)
			{
				m_ptr = m_head;
			}
			return *this;
		}

		Iterator operator+(int a_number)
		{
			for (int i = a_number; i > 0 && m_ptr != nullptr; i--)
			{
				m_ptr = m_ptr->m_next;
			}
			if (m_ptr == nullptr)
			{
				m_ptr = m_tail;
			}
			return *this;
		}

		bool operator!=(const Iterator& a_other)
		{
			return m_ptr != a_other.m_ptr;
		}

		bool operator==(const Iterator& a_other)
		{
			return m_ptr == a_other.m_ptr;
		}
	};

	~LinkedList()
	{
		Node* l_current = m_head->m_next;
		while (l_current != m_tail)
		{
			delete l_current->m_prev;
			l_current = l_current->m_next;
		}
		delete l_current->m_prev;
		delete l_current;
	}

	LinkedList(const LinkedList& a_other)
	{
		Node* l_current = a_other.m_head;
		while (l_current != nullptr)
		{
			push_back(l_current->m_value);
			l_current = l_current->m_next;
		}
		m_size = a_other.m_size;
	}

	LinkedList(LinkedList&& a_other)
	{
		m_head = a_other.m_head;
		m_tail = a_other.m_tail;
		m_size = a_other.m_size;
		a_other.m_head = nullptr;
		a_other.m_tail = nullptr;
		a_other.m_size = 0;
	}

	LinkedList() : m_head(), m_tail(), m_size() { }

	Node* push_back(const T& a_element)
	{
		Node* l_node = new Node{ a_element };

		if (m_size == 0)
		{
			m_head = m_tail = l_node;
			++m_size;
		}
		else
		{
			m_tail->m_next = l_node;
			l_node->m_prev = m_tail;
			m_tail = l_node;
			++m_size;
		}
		return l_node;
	}

	void pop_front()
	{
		m_head = m_head->m_next;
		delete m_head->m_prev;
		--m_size;
	}

	void pop_back()
	{
		m_tail = m_tail->m_prev;
		delete m_tail->m_next;
		--m_size;
	}

	void clear()
	{
		~LinkedList();
		m_head = m_tail = nullptr;
		m_size = 0;
	}

	bool empty()
	{
		return m_size == 0;
	}

	void remove(Node* a_position)
	{
		if (a_position == m_head)
		{
			pop_front();
		}
		else if (a_position == m_tail)
		{
			pop_back();
		}
		else
		{
			a_position->m_prev = a_position->m_next;
			a_position->m_next = a_position->m_prev;
			delete m_tail;
			--m_size;
		}
	}

	Node* insert_after(const T& a_element, Node* a_position)
	{
		Node* l_node = new Node{ a_element };
		l_node->m_prev = a_position;
		l_node->m_next = a_position->m_next;
		(a_position->m_next)->m_prev = l_node;
		a_position->m_next = l_node;
		++m_size;
		return l_node;
	}

	void reverse()
	{
		Node* temp = m_head;
		m_head = m_tail;
		m_tail = temp;
		Node* l_current = m_head;
		while (l_current != nullptr)
		{
			temp = l_current->m_next;
			l_current->m_next = l_current->m_prev;
			l_current->m_prev = temp;
			l_current = l_current->m_next;
		}
	}

	Iterator begin()
	{
		return m_head;
	}

	Iterator end()
	{
		return nullptr;
	}

	Iterator get_tail()
	{
		return m_tail;
	}

	LinkedList& operator=(const LinkedList& a_other)
	{
		clear();

		Node* l_current = a_other.m_head;
		while (l_current != nullptr)
		{
			push_back(l_current->m_value);
			l_current = l_current->m_next;
		}
		m_size = a_other.m_size;

		return *this;
	}

	LinkedList& operator=(LinkedList&& a_other)
	{
		clear();

		m_head = a_other.m_head;
		m_tail = a_other.m_tail;
		m_size = a_other.m_size;
		a_other.m_head = nullptr;
		a_other.m_tail = nullptr;
		a_other.m_size = 0;

		return *this;
	}

private:
	Node* m_head;
	Node* m_tail;
	int m_size;
};

