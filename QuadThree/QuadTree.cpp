#include "QuadTree.h"

QuadTree::QuadTree(){}

QuadTree::QuadTree(double x, double y, double w, double h) : m_x{ x }, m_y{ y }, m_w{ w }, m_h{ h }
{ }

void QuadTree::SubDivide()
{
	if(IsSubDivided) return;
	else{ 
		ne = new QuadTree(m_x + m_w / 2, m_y + m_h / 2, m_w / 2, m_h / 2);
		nw = new QuadTree(m_x - m_w / 2, m_y + m_h / 2, m_w / 2, m_h / 2);	
		se = new QuadTree(m_x + m_w / 2, m_y - m_h / 2, m_w / 2, m_h / 2);
		sw = new QuadTree(m_x - m_w / 2, m_y - m_h / 2, m_w / 2, m_h / 2);
	}
}

void QuadTree::Find()
{
}

void QuadTree::Insert()
{
}
