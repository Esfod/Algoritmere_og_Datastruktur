#include <iostream>
#include "QuadTree.h"

int main()
{
	QuadTree* qtree = new QuadTree(200, 200, 200, 200);
	qtree->SubDivide();
	qtree->nw->SubDivide();
	qtree->ne->SubDivide();
	qtree->ne->nw->SubDivide();
	qtree->PrintCordinates();
	return 0;
}