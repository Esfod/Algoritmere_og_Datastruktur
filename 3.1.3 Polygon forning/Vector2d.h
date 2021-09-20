#pragma once
#include <cmath>
class Vector2d
{
public:
	double x;
	double y;

	Vector2d operator + (const Vector2d& v) const
	{
		Vector2d u;
		u.x = x + v.x;
		u.y = y + v.y;
		return u;
	};

	Vector2d operator - (const Vector2d& v) const
	{
		Vector2d u;
		u.x = x - v.x;
		u.y = y - v.y;
		return u;
	};

	double operator * (const Vector2d& v) const
	{
	/*
		Vector2d U;
			U.x = x * v.x;
			U.y = y * v.y;

			return U.x + U.y;
	*/
		Vector2d U;
		U.x = abs(x - v.x);
		U.y = abs(y - v.y);

		return abs(sqrt(pow(U.x, 2) + pow(U.y, 2)));
	};

	Vector2d operator / (int d)
	{
		Vector2d u;
		u.x = x / d;
		u.y = y / d;
		return u;
	};
};

