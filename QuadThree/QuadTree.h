#pragma once
#include "Vector2d.h"
class QuadTree
{
public:
	QuadTree();
	QuadTree(double x, double y, double w, double h);
	void SubDivide();
	void Find();
	void Insert();

private:
	double m_x, m_y, m_w, m_h{ 0 };
	QuadTree* nw{ nullptr };
	QuadTree* ne{ nullptr };
	QuadTree* sw{ nullptr };
	QuadTree* se{ nullptr };
	bool IsSubDivided{ false };
};

