#pragma once

class QuadTree
{
public:
	QuadTree();
	QuadTree(double x, double y, double w, double h);
	void SubDivide();
	void PrintCordinates();


	QuadTree* nw{ nullptr };
	QuadTree* ne{ nullptr };
	QuadTree* sw{ nullptr };
	QuadTree* se{ nullptr };

private:
	double m_x, m_y, m_w, m_h{ 0 };
	bool IsSubDivided{ false };
};