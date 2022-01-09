#pragma once
#include "vector"

class BinaryNode
{
private:

	char m_data;

	int m_frekvens;

	BinaryNode* m_left;

	BinaryNode* m_right;

	std::vector<BinaryNode*> vec;

public:

	explicit BinaryNode(char data) : m_data{ data }, m_left{ nullptr }, m_right{ nullptr }, m_frekvens{ 1 } { }

	void insert(char data);

	void print() const;

	void printfre();

	void nre_intrav();

	void selection_sort();

};

