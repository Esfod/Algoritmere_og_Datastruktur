#pragma once
#include <vector>
#include "Vector2d.h"

class PlainRectangle
{
private:
	Vector2d m_v1;
	Vector2d m_v2;
	Vector2d m_v3;
	Vector2d m_v4;
	static std::vector<PlainRectangle> m_rectangles;
	double getAreal(Vector2d& a, Vector2d& b, Vector2d& c, const Vector2d& d);
public:
	PlainRectangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4);
	void subDivide(const Vector2d& a, const Vector2d& b, const Vector2d& c, const Vector2d& d, int n);
	void makeRectangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4);
	void print() const;
};

