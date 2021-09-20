#include "PlainRectangle.h"
#include <iostream>

std::vector<PlainRectangle> PlainRectangle::m_rectangles;

PlainRectangle::PlainRectangle(const Vector2d& a, const Vector2d& b, const Vector2d& c, const Vector2d& d) : m_v1{ a }, m_v2{ b }, m_v3{ c }, m_v4{ d }
{
	
}

void PlainRectangle::subDivide(const Vector2d& a, const Vector2d& b, const Vector2d& c, const Vector2d& d, int n)
{
	if(n > 0) {
		Vector2d v1 = (a + b) / 2;
		Vector2d v2 = (b + c) / 2;
		Vector2d v3 = (c + d) / 2;
		Vector2d v4 = (d + a) / 2;
		Vector2d m = (a + c) / 2;
		m_rectangles.push_back(PlainRectangle(a, b, c, d));  //Før vær gang man deler opp en firkant
		subDivide(a, v1, m, v4, n - 1);
		subDivide(v1, b, v2, m, n - 1);
		subDivide(m, v2, c, v3, n - 1);
		subDivide(v4, m, v3, d, n - 1);
	} 
	else
		makeRectangle(a , b , c , d);
}

void PlainRectangle::subDivide(const Vector2d& a, const Vector2d& b, const Vector2d& c, const Vector2d& d, double n)
{
	int s{0};
	double x = getArealRectangle(a,b,c,d);
	//std::cout << "\nareal ==== " << x << std::endl;
	while (x > n) {
		x /= 4;
		s++;
	}

	subDivide(a, b, c, d, s);
}

void PlainRectangle::makeRectangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4)
{
	m_rectangles.push_back(PlainRectangle(v1, v2, v3, v4));
}

double PlainRectangle::getArealRectangle() const 
{
	return (m_v1 * m_v2) * (m_v1 * m_v4);
}

double PlainRectangle::getArealRectangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4) const
{
	return (v1 * v2) * (v1 * v4);
}

void PlainRectangle::print() const
{
	std::cout << "n = " << m_rectangles.size() << std::endl;
	for (auto it = m_rectangles.begin(); it != m_rectangles.end(); it++)
	{
		auto t{ *it };

		Vector2d v1{ t.m_v1 + t.m_v2 };
		Vector2d v2{ t.m_v4 + t.m_v1 };

		std::cout << " ( " << t.m_v1.x << " , " << t.m_v1.y << " ) ";
		std::cout << " ( " << t.m_v2.x << " , " << t.m_v2.y << " ) ";
		std::cout << " ( " << t.m_v3.x << " , " << t.m_v3.y << " ) ";
		std::cout << " ( " << t.m_v4.x << " , " << t.m_v4.y << " ) ";
		std::cout << "  Area is : " << getArealRectangle(t.m_v1,t.m_v2,t.m_v3,t.m_v4); //getArealRectangle(t.m_v1, t.m_v2, t.m_v3, t.m_v4);
		std::cout << std::endl;
	}
}
