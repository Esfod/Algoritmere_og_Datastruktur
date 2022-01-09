#include "BinaryNode.h"
#include <iostream>
#include <stack>

void BinaryNode::insert(char data)
{
	if (data == m_data)
	{
		m_frekvens++;
	}
	else if (data < m_data)
	{
		if (m_left)
			m_left->insert(data);
		else
			m_left = new BinaryNode(data);
	}
	else if (data > m_data)
	{
		if (m_right)
			m_right->insert(data);
		else
			m_right = new BinaryNode(data);
	}
}

void BinaryNode::print() const
{
	if (m_left)
		m_left->print();
	std::cout << "Verdi :" << m_data << " Frekvens: " << m_frekvens << std::endl;
	if (m_right)
		m_right->print();
}

void BinaryNode::nre_intrav()
{
	std::stack<BinaryNode*> stakk;
	BinaryNode* p{ this };
	do
	{
		while (p != nullptr)
		{
			stakk.push(p);
			p = p->m_left;
		}
		if (!stakk.empty())
		{
			p = stakk.top();
			vec.push_back(p);
			stakk.pop();
			p = p->m_right;
		}

	} while (!stakk.empty() || p != nullptr);
}

void BinaryNode::printfre()
{
	nre_intrav();
	selection_sort();
	for (auto x : vec)
	{
		std::cout << "Verdi : " << x->m_data << " Frekvens: " << x->m_frekvens << std::endl;
	}
}

void BinaryNode::selection_sort()
{
	for (auto i{0}; i < vec.size();i++)
	{
		for (auto j{ i+1 }; j < vec.size(); j++)
		{
			if (vec[i]->m_frekvens > vec[j]->m_frekvens)
				std::swap(vec[i], vec[j]);
		}
	}
}