#pragma once
#include <iostream>

template <class T>
class temp_stakk
{
public:
	temp_stakk(const int& size);
	void push(T a);
	void pop();
	T top();
	int size();
	bool empty();
	T getData(int a);
private:
	T* m_data;
	int m_top;
	int m_size;
	int m_max_size;
};

template<class T>
inline temp_stakk<T>::temp_stakk(const int& size) : m_top(0), m_size(0), m_max_size(size)
{
	m_data = new T[size];
}

template<class T>
inline void temp_stakk<T>::push(T a)
{
	if (m_size == m_max_size)
		std::cout << "char_stakk is full\n";

	m_top = m_size;
	m_data[m_size] = a;
	m_size++;
}

template<class T>
inline void temp_stakk<T>::pop()
{
	if (empty())
	{
		std::cout << "can't pop when stack is empty\n";
		return;
	}
	
	m_top--;
	m_size--;
}

template<class T>
inline T temp_stakk<T>::top()
{
	return m_data[m_top];
}

template<class T>
inline int temp_stakk<T>::size()
{
	return m_size;
}

template<class T>
inline bool temp_stakk<T>::empty()
{
	if (m_size == 0)
		return true;
	return false;
}

template<class T>
inline T temp_stakk<T>::getData(int a)
{
	return m_data[a];
}
