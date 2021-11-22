#include <iostream>
#include "hash.h"
#include <d3d12.h>

int main()
{
	hashTable* myHash = new hashTable();

	bool isHashEmpty = myHash->IsEmpty();

	myHash->insert("hei");
	myHash->insert("hei");
	myHash->insert("pølsefest");
	myHash->insert("hei");

	myHash->PrintTable();

	isHashEmpty = myHash->IsEmpty();
	
	return 0;
}