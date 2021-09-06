#include "temp_queue.h"
#include <iostream>

template<class T>
temp_queue<T>::temp_queue(const int& size) : m_size(0), m_front(0), m_back(0), m_max_size(size)
{
	m_data = new T[size];
}

template<class T>
temp_queue<T>::~temp_queue()
{
	delete[] m_data;
	m_size = m_front = m_back = 0;
}

template<class T>
void temp_queue<T>::push(const T& a)
{
	if (m_size == m_max_size)
	{
		std::cout << "\nkøen er full";
		return;
	}

	m_data[m_back] = a;
	m_back++;
	m_size++;
}

template<class T>
void temp_queue<T>::pop()
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

template<class T>
T temp_queue<T>::front()
{
	if (m_size > 0)
	{
		return m_data[m_front];
	}
}

template<class T>
int temp_queue<T>::size()
{
	return m_size;
}

template<class T>
bool temp_queue<T>::empty()
{
	if (m_size > 0) return false;
	return true;
}

template<class T>
T temp_queue<T>::getdata(int a)
{
	if (a >= m_back) return false;
	else return m_data[a];
}