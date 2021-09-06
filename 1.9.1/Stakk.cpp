#include "Stakk.h"
#include "Stakk.h"
#include "Node.h"
#include <iostream>

namespace ADS101
{

	Stakk::Stakk() : m_top{ nullptr }, m_bottom{ nullptr }
	{

	}

	Stakk::~Stakk()
	{

	}

	void Stakk::push(const char& ch)
	{
		CharNode* ny = new CharNode(ch);
		if (m_top != nullptr)
			ny->settNeste(m_top);
		m_top = ny;
		if (m_top == nullptr)
			m_bottom = m_top;
	}

	void Stakk::pop()
	{
		if (m_top != nullptr && m_top->hentNeste() != nullptr)
		{
			CharNode* ut = m_top;
			m_top = m_top->hentNeste();
			delete ut;
		}
		else
			m_bottom = nullptr;
	}

	char Stakk::top()
	{
		return m_top->hentData();
	}

	int Stakk::size()
	{
		return m_top->hentAntall();
	}

	bool Stakk::empty()
	{
		if (m_top != nullptr) return false;
		else return true;
	}
	void Stakk::writeOutStack()
	{
		m_top->skrivBaklengs();
	}
}