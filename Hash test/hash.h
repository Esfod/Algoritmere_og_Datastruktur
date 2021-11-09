#pragma once
#include <iostream>
#include <cstring>
#include <queue>
#include <array>

using namespace std;

class hashTable
{
private:
	static const int sizeOfTable = 15;
	static const int numbOfValues = 3;

	struct hashValues
	{
		int key{ sizeOfTable + 1 };
		array<string, numbOfValues> values { "" };
	};

	array<hashValues,sizeOfTable> table;

	int hashFunction(string key);
	int reHash1(string key);
	bool IsValuesFull(int key);

public:
	hashTable();
	void insert(string value);
	void remove(string key);
	bool IsEmpty() const;
	void PrintTable();
	int Find(string key);
};

