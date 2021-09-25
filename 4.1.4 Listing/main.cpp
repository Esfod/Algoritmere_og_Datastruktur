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

	btre->re_intrav();
	std::cout << std::endl;
	btre->nre_intrav();
	std::cout << "\nrepost" << std::endl;
	btre->re_potrav();
	std::cout << std::endl;
	btre->nre_potrav();
	std::cout << "\nnumber of nodes is: " << btre->size() << std::endl;
	std::cout << "\nThe height is: " << btre->findHeight(btre) << std::endl;
	bool IsBalanced{ btre->IsBineryTreeBalanced(btre) };
	if(IsBalanced) std::cout << "\nThis binarythree is Balanced" << std::endl;
	else std::cout << "\nThis binarythree not is Balanced" << std::endl;
}