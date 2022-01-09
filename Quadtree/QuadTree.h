#pragma once
#include <vector>
struct Points
{
	Points() { m_x = 0; m_y = 0; }
	Points(double x, double y) : m_x(x), m_y{ y } {}
	double m_x, m_y;
};

class QuadTree
{
public:
	QuadTree();

	QuadTree(Points a, Points b, Points c, Points d);

	void SubDivide();

	void PrintCordinates();

	std::vector<Points*> vecPoints;

	void SetPoints(int amount, double pos_x_min, double pos_x_max, double pos_y_min, double pos_y_max);


	QuadTree* nw{ nullptr };
	QuadTree* ne{ nullptr };
	QuadTree* sw{ nullptr };
	QuadTree* se{ nullptr };

private:
	Points m_a, m_b, m_c, m_d;
	bool IsSubDivided{ false };

	void checkForPoints(QuadTree* qt)
};

