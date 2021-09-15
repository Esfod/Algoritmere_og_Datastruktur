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

	btre->intrav();

}