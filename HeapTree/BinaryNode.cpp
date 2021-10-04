#include "BinaryNode.h"
#include <iostream>

BinaryNode::BinaryNode() {}

BinaryNode::BinaryNode(int data, BinaryNode* left, BinaryNode* right) : m_data{ data }, m_left{ left }, m_right{right}
{

}


void BinaryNode::Pop()
{
	if (m_right && m_left)
	{
		if (m_right->m_data > m_left->m_data)
		{
			m_data = m_left->m_data;
			m_left->Pop();
		}
		else if(m_right->m_data < m_left->m_data)
		{
			m_data = m_right->m_data;
			m_right->Pop();
		}
		if (m_data == m_right->m_data)
			m_right = nullptr;
		else if (m_data == m_left->m_data)
			m_left = nullptr;
	}
	else if (m_right)
	{
		m_data = m_right->m_data;
		m_right->Pop();
		if (m_data == m_right->m_data)
			m_right = nullptr;
	}
	else if (m_left)
	{
		m_data = m_left->m_data;
		m_left->Pop();
		if (m_data == m_left->m_data)
			m_left = nullptr;
	}
}

void BinaryNode::Push(int a)
{
	int temp { 0 };
	if (m_data > a)
	{
		int temp = m_data;
		m_data = a;
	}
}

int BinaryNode::Top() { return m_data; }


int BinaryNode::Size(int a)
{
	a++;
	if (m_left) a = m_left->Size(a);
	if (m_right) a = m_right->Size(a);
	return a;
}

int BinaryNode::FindMaxHeight(BinaryNode* p)
{
	if (p == nullptr)
		return 0;

	return FindMax(FindMaxHeight(p->m_left), FindMaxHeight(p->m_right) + 1);
	//travels down the right and left tree and finds the highest and +1 with account of the root
}

int BinaryNode::FindMinHeight(BinaryNode* p)
{
	if (p == nullptr)
		return 0;

	return FindMin(FindMinHeight(p->m_left), FindMinHeight(p->m_right) + 1);
	//travels down the right and left tree and finds the highest and +1 with account of the root
}

int BinaryNode::FindMax(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int BinaryNode::FindMin(int a, int b)
{
	if (a <= b)
		return a;
	else
		return b;
}

void BinaryNode::PrintByLayer()
{
	std::cout << m_data << ", ";
	if (m_left) m_left->PrintByLayer();
	if (m_right) m_right->PrintByLayer();
}