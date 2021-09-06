#include "char_queue.h"
#include <iostream>

char_queue::char_queue(const int& size) : m_size(0), m_front(0), m_back(0), m_max_size(size)
{
	m_data = new char[size];
}

char_queue::~char_queue()
{
	delete [] m_data;
}

void char_queue::push(const char& ch)
{
	if (m_size == m_max_size)
	{
		std::cout << "\nkøen er full";
		return;
	}

	m_data[m_back] = ch;
	m_back++;
	m_size++;
}

void char_queue::pop()
{
	if (empty())
	{
		std::cout << "\n the queue is empty";
		return;
	}

	for (auto i = 0; i < m_size; i++)
	{
		m_data[i] = m_data[i + 1];
	}

	m_back--;
	m_size--;
}

char char_queue::front()
{
	if (m_size > 0)
	{
		return m_data[m_front];
	}
}
int char_queue::size()
{
	return m_size;
}

bool char_queue::empty()
{
	if (m_size > 0) return false;
	return true;
}

char char_queue::getdata(int a)
{
	if (a >= m_back) return false;
	else return m_data[a];
}