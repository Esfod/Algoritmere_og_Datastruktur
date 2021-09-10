#include "char_stakk.h"
#include <iostream>

char_stakk::char_stakk(const int size) : m_size(0), m_top(0), m_max_size(size)
{
	m_data = new char[size];
}

void char_stakk::push(const char& ch)
{
	if (m_size == m_max_size)
		std::cout << "char_stakk is full\n";
	
	m_top = m_size;
	m_data[m_size] = ch;
	m_size++;
}

void char_stakk::pop()
{
	if (empty())
	{
		std::cout << "can't pop when stack is empty\n";
		return;
	}

	m_top--;
	m_size--;
}

char char_stakk::top()
{
	return m_data[m_top];
}

int char_stakk::size()
{
	return m_size;
}

bool char_stakk::empty()
{
	if(m_size == 0)
		return true;
	return false;
}

char char_stakk::getData(int a)
{
	return m_data[a];
}
