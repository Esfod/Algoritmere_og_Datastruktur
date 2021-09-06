#pragma once

#include <iostream>
#include "TempNode.h"

namespace ADS101
{
	template<class T>
	class TempStakk
	{
	public:
		TempStakk();
		void push(T ch);
		void pop();
		T top();
		int size();
		bool empty();
		void writeOutStack();

	private:
		TempNode<T>* m_top;
		TempNode<T>* m_bottom;
	};


	template <class T>
	TempStakk<T>::TempStakk() : m_top{ nullptr }, m_bottom{ nullptr }
	{

	}

	template <class T>
	void TempStakk<T>::push(T ch)
	{
		TempNode<T>* ny = new TempNode<T>(ch);
		if (m_top != nullptr)
			ny->settNeste(m_top);
		m_top = ny;
		if (m_top == nullptr)
			m_bottom = m_top;
	}

	template <class T>
	void TempStakk<T>::pop()
	{
		if (m_top != nullptr && m_top->hentNeste() != nullptr)
		{
			TempNode<T>* ut = m_top;
			m_top = m_top->hentNeste();
			delete ut;
		}
		else
			m_bottom = nullptr;
	}

	template <class T>
	T TempStakk<T>::top()
	{	
		return m_top->hentData();
	}

	template <class T>
	int TempStakk<T>::size()
	{
		return m_top->hentAntall();
	}

	template <class T>
	bool TempStakk<T>::empty()
	{
		if (m_top != nullptr) return false;
		else return true;
	}

	template <class T>
	void TempStakk<T>::writeOutStack()
	{
		m_top->skrivBaklengs();
	}
}