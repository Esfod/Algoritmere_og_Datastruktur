#include <iostream>
#include "QuadTree.h"

int main()
{
	QuadTree* qtree = new QuadTree(200, 200, 200, 200); // x , y (cordinate for the centre of the quadtree), width , heith 
	qtree->SubDivide();
	qtree->nw->SubDivide();
	qtree->ne->SubDivide();
	qtree->PrintCordinates();
	return 0;
}