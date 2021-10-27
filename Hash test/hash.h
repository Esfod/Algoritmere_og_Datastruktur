#pragma once
#include <iostream>
#include <cstring>
#include <queue>
#include <array>

using namespace std;

class hashTable
{
private:
	static const int hashListLenght = 10;
	static const int hashListHeight = 3;
	array<array<pair<int, string>,hashListHeight>, hashListLenght> table;

public:
	int hashFunction(string key);
	int reHash(string key);
	void insert(string value);
	void remove(int key);
	bool IsEmpty() const;
	bool IsQueueFull(int key);
	void PrintTable();
	void Find(int key);
	
};

