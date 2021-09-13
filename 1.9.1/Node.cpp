#include <string>
#include <sstream>
#include <iostream>
#include "Node.h"

namespace ADS101
{
	int CharNode::s_antall;

	CharNode::CharNode(char tegn, CharNode* neste) : m_tegn(tegn), m_neste(neste)
	{
		s_antall++; //adds one to the size so we easy can work with the size of the stack
	}

	std::string CharNode::toString() const
	{
		std::ostringstream oss;
		oss << m_tegn;
		return oss.str();
	}

	CharNode* CharNode::hentNeste() const
	{
		return m_neste;
	}

	void CharNode::skrivBaklengs() const
	{
		if (m_neste) // if m_neste is not an nullptr means it is not at the bottom 
			m_neste->skrivBaklengs(); // then it will go and start skrivBaklengs again
		std::cout << m_tegn; // when it findes the bottom it will start priting out from the bottom up
	}

	int CharNode::hentAntall()
	{
		return s_antall; 
	}

	void CharNode::settNeste(CharNode* neste)
	{
		m_neste = neste;
	}

	CharNode::~CharNode()
	{
		s_antall--;
	}
	char CharNode::hentData()const
	{
		return m_tegn;
	}
}