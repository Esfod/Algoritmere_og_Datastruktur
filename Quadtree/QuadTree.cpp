#include "QuadTree.h"
#include <iostream>

QuadTree::QuadTree() 
{ 
	m_a.m_x, m_b.m_x, m_c.m_x, m_d.m_x = 0.0;
	m_a.m_y, m_b.m_y, m_c.m_y, m_d.m_y = 0.0;

}

QuadTree::QuadTree(Points a, Points b, Points c, Points d) : m_a{ a }, m_b{ b }, m_c{ c }, m_d{ d }
{ }

void QuadTree::SubDivide()
{
	if (IsSubDivided) return;
	else if() {
		ne = new QuadTree(Points(m_a.m_x/2,m_a.m_y/2), Points(m_b.m_x, m_b.m_y / 2), Points(m_c.m_x, m_c.m_y), Points(m_a.m_x/2, m_a.m_y));
		nw = new QuadTree(Points(m_a.m_x, m_a.m_y / 2), Points(m_b.m_x / 2, m_b.m_y / 2), Points(m_c.m_x / 2, m_c.m_y), Points(m_a.m_x, m_a.m_y));
		se = new QuadTree(Points(m_a.m_x/2, m_a.m_y), Points(m_b.m_x, m_b.m_y), Points(m_c.m_x, m_c.m_y/2), Points(m_a.m_x/2, m_a.m_y/2));
		sw = new QuadTree(Points(m_a.m_x, m_a.m_y), Points(m_b.m_x / 2, m_b.m_y), Points(m_c.m_x /2, m_c.m_y/2), Points(m_a.m_x, m_a.m_y/2));
	}
}

void QuadTree::PrintCordinates()
{
	if (!ne && !nw && !se && !sw) return;
	if (ne) ne->PrintCordinates();
	if (nw) nw->PrintCordinates();
	if (se) se->PrintCordinates();
	if (sw) sw->PrintCordinates();
}

void QuadTree::SetPoints(int amount, double pos_x_min, double pos_x_max, double pos_y_min, double pos_y_max)
{
	for (int i = 0; i < amount; i++)
	{
		auto x1 = std::rand() % (int)pos_x_max + (int)pos_x_max;
		int delta = std::rand() % 10;
		double xdec = (double)delta / 10;
		double x = x1 + xdec;

		auto y1 = std::rand() % (int)pos_y_max + (int)pos_y_min;
		delta = std::rand() % 10;
		double ydec = (double)delta / 10;
		double y = y1 + ydec;
		Points* a = new Points(x,y);
		vecPoints.push_back(a);
	}
}

void QuadTree::checkForPoints(QuadTree* qt)
{
	for (auto x : vecPoints)
	{
		if(x->m_x < )
	}
	if()
}
