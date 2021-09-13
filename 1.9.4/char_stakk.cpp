#include "char_stakk.h"
#include <iostream>

char_stakk::char_stakk(const int size) : m_size(0), m_top(0), m_max_size(size)
{
	m_data = new char[size]; //creats the array
}

void char_stakk::push(const char& ch)
{
	if (m_size == m_max_size) // cheacks if the stakk has reached the max size
	{
		std::cout << "char_stakk is full\n";
		return; //quick exit if its full
	}
		
	
	m_top = m_size;
	m_data[m_top] = ch;
	m_size++;
}

void char_stakk::pop()
{
	if (empty()) //if the queue is empty, there is notihing to remove
	{
		std::cout << "can't pop when stack is empty\n";
		return;
	}
	//goes down one size 
	m_top--;
	m_size--;
}

char char_stakk::top()
{
	if (!empty()) //checks if the queue is empty
		return m_data[m_top];
	return false;
}

int char_stakk::size()
{
	return m_size;
}

bool char_stakk::empty()
{
	if(m_size == 0) return true;
	return false;
}

char char_stakk::getData(int a)
{
	if (a >= m_top) return false;
	else return m_data[a];
}
