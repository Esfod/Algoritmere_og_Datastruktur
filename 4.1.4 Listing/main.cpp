#include <iostream>
#include "BinaryNode.h"

int main(int argc, char *argv[])
{
	BinaryNode* h = new BinaryNode('d');
	BinaryNode* v = new BinaryNode('a');
	v = new BinaryNode('b', v, h);
	BinaryNode* btre = new BinaryNode('g');
	h = new BinaryNode('p');
	btre = new BinaryNode('i', btre, h);
	btre = new BinaryNode('f', v, btre);

	std::cout << "\n\nin-order" << std::endl;
	btre->re_intrav();
	std::cout << std::endl;
	btre->nre_intrav();
	std::cout << "\n\nre-post" << std::endl;
	btre->re_potrav();
	std::cout << std::endl;
	btre->nre_potrav();
	std::cout << "\n\nnumber of nodes is: " << btre->size() << std::endl;
	std::cout << "\n\nThe height is: " << btre->findHeight(btre) << std::endl;
	bool IsBalanced{ btre->IsBineryTreeBalanced(btre) };
	if(IsBalanced) std::cout << "\n\nThis binarythree is Balanced" << std::endl;
	else std::cout << "\n\nThis binarythree not is Balanced" << std::endl;
}