#include <iostream>
#include "QuadTree.h"

int main()
{
	Points a(-2, -2);
	Points b(-2, 2);
	Points c(2, 2);
	Points d(2, -2);

	QuadTree* qtree = new QuadTree(a, b, c, d); 
	
	qtree->SetPoints(20, -2, -2, 2, 2);
	qtree->SetPoints(20, 0, 0, 2, 2);


	return 0;
}