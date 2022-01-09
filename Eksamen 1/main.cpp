#include <iostream>
#include "BinaryNode.h"

int main()
{
	std::string s{ "det er enklere å løse et algoritmisk problem enn et demokratisk problem" };
	BinaryNode* a = new BinaryNode(s[0]);
	for (auto i = 1; i < s.size(); i++)
	{
		a->insert(s[i]);
	}
	
	a->printfre();
	return 0;
}