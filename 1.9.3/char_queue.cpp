#include "char_queue.h"
#include <iostream>

char_queue::char_queue(const int& size) : m_size(0), m_front(0), m_back(0), m_max_size(size)
{
	m_data = new char[size];			//creats the array
}


void char_queue::push(const char& ch)
{
	if (m_size == m_max_size)			// cheacks if the queue has reached the max size
	{
		std::cout << "\nthe queue is full"; 
		return;							//quick exit if its full
	}

	m_data[m_back] = ch;				//sets the inputed value in the array
	m_back++;
	m_size++;
}

void char_queue::pop()
{
	if (empty())						//if the queue is empty, there is notihing to remove
	{
		std::cout << "\n the queue is empty";
		return;							//quick exit if its full
	}

	for (auto i = 0; i < m_size; i++)	//takes the value behind in the queue and overwrites the value infront
	{
		m_data[i] = m_data[i + 1];
	}

	m_back--; 
	m_size--;
}

char char_queue::front()
{
	if (!empty())						//checks if the queue is empty
		return m_data[m_front];
	return false;
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
	if (a >= m_back || empty()) return false; //checks that the inserted parameter is not above the size of the queue
	else return m_data[a];
}