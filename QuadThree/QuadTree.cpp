#include "QuadTree.h"
#include <iostream>

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

void QuadTree::PrintCordinates()
{
	if(!ne && !nw && !se && !sw) std::cout << '(' << m_x - m_w << ',' << m_y - m_h << ") (" << m_x + m_w << ',' << m_y - m_h << ") (" << m_x + m_w << ',' << m_y + m_h << ") (" << m_x - m_w << ',' << m_y + m_h << ")\n" << std::endl;
	if (ne) ne->PrintCordinates();
	if (nw) nw->PrintCordinates();
	if (se) se->PrintCordinates();
	if (sw) sw->PrintCordinates();
}