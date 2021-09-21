#include "BinaryNode.h"
#include <iostream>
#include <stack>
#include <queue>

BinaryNode::BinaryNode() {}

BinaryNode::BinaryNode(char data, BinaryNode* left, BinaryNode* right) : m_data{ data }, m_right{ right }, m_left{left} { }

char BinaryNode::getData() { return m_data; }

BinaryNode *BinaryNode::find(char data)
{
	if (m_data == data)
		return this;
	else if (data < m_data && m_left != nullptr)
		return m_left->find(data);
	else if (m_right)
		return m_right->find(data);
	return nullptr;
}

void BinaryNode::insert(char data)
{
	if (data < m_data)
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




void BinaryNode::re_intrav()
{
	if (m_left)
		m_left->re_intrav();
	std::cout << m_data;
	if (m_right)
		m_right->re_intrav();
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
			std::cout << p->m_data;
			stakk.pop();
			p = p->m_right;
		}
	
	} while (!stakk.empty() || p != nullptr);
}

void BinaryNode::re_potrav()
{
	if (m_left)
		m_left->re_potrav();
	if (m_right)
		m_right->re_potrav();
	std::cout << m_data;
}

void BinaryNode::nre_potrav()
{
	std::stack<BinaryNode*> stakk;
	std::stack<BinaryNode*> toprint;
	BinaryNode* p { this };
	do {
		while (p != nullptr)
		{
			stakk.push(p);
			toprint.push(p);
			p = p->m_right;
		}
		if (!stakk.empty())
		{
			p = stakk.top();
			stakk.pop();
			p = p->m_left;
		}
	} while (!stakk.empty() || p != nullptr);

	while (!toprint.empty())
	{
		p = toprint.top();
		toprint.pop();
		std::cout << p->m_data;
	}
}

int BinaryNode::size()
{
	std::stack<BinaryNode*> stakk;
	BinaryNode* p{ this };
	int i{ 0 };
	do {
		while (p != nullptr)
		{
			stakk.push(p);
			p = p->m_left;
		}
		if (!stakk.empty())
		{
			p = stakk.top();
			stakk.pop();
			p = p->m_right;
		}
		i++;
	} while (!stakk.empty() || p != nullptr);
	return i;
}

int  BinaryNode::hight()
{
	int h {0};
	return h;
}