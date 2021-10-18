#include <iostream>
#include "BinaryNode.h"

int main()
{
	BinaryNode* a = new BinaryNode(55);
	BinaryNode* b = new BinaryNode(40);
	BinaryNode* c = new BinaryNode(30,b,a);
	
	BinaryNode* d = new BinaryNode(70);

	BinaryNode* e = new BinaryNode(20,d);
	
	BinaryNode* heep = new BinaryNode(15,c,e);


	heep->PrintByLayer();
	std::cout << heep->Top() << std::endl;
	std::cout << heep->Size() << std::endl;
	heep->Pop();
	heep->Pop();
	heep->Pop();
	std::cout << heep->Top() << std::endl;
	std::cout << heep->Size() << std::endl;
	
	
	return 0;
}