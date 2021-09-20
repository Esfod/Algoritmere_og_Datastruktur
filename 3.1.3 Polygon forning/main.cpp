#include <iostream>
#include "PlainRectangle.h"
#include "Vector2d.h"


int main()
{
	Vector2d a{ 0 , 0 };
	Vector2d b{ 1 , 0 };
	Vector2d c{ 1 , 1 };
	Vector2d d{ 0 , 1 };
	PlainRectangle rect( a , b , c , d );
	//rect.subDivide(a, b, c, d, 2);
	rect.subDivide(a, b, c, d, 0.9);
	rect.print();
	return 0;
}