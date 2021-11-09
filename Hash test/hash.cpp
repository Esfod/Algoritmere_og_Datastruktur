#include "hash.h"
#include <iostream>

using namespace std;
hashTable::hashTable()
{
	for (size_t i{ 0 }; i < sizeOfTable; i++)
		table[i].key = i;
}

int hashTable::hashFunction(string key)
{
	int delta{ 0 };
	for (int i{0}; i < key.size(); i++)
	{
		delta += key[i];
	}
	return delta % sizeOfTable;
}

int hashTable::reHash1(string key)
{
	int delta{ 0 };
		delta = key[0];
	return delta % sizeOfTable;
}

void hashTable::insert(string value)
{
	int hashValue{ hashFunction(value) };
	if (IsValuesFull(hashValue))
	{
		hashValue = reHash1(value);
		if (IsValuesFull(hashValue));
		{
			cout << "could not insert value" << endl;
			return;
		}
	}


	for (auto& y : table[hashValue].values)
	{
		if (y != "") continue;
		y = value;
		break;
	}
}

void hashTable::remove(string key)
{
	int delta = { Find(key) };
	if (delta > sizeOfTable - 1) cout << "Could not found the value in the table" << endl;
	else 
	{
		for (auto y : table[delta].values)
			if (key == y) y = "";
	}
}

bool hashTable::IsEmpty() const
{
	for (auto x : table)
	{
		for (auto y : x.values)
		{
			if (y != "")
				return false;
		}
	}

	return true;
}

bool hashTable::IsValuesFull(int key)
{
	int x{0};
	for (auto y : table[key].values)
	{
		if (y != "")
			x++;
	}
	if (x == numbOfValues)
		return true;
	else
		return false;
}

void hashTable::PrintTable()
{
	for (auto x : table)
	{
		cout << "key:" << x.key << "\t Values: ";
		for (auto y : x.values)
		{
			cout << y << "\t";
		}
		cout << endl;
	}
}

int hashTable::Find(string key)
{
	int keykey{ 0 };
	bool found{ false };
	while (!found)
	{
		for (size_t i{ 0 }; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				keykey = hashFunction(key);
				for (auto y : table[keykey].values)
				{
					if (key == y)
					{
						return keykey;
					}
				}
				break;

			case 1:
				keykey = reHash1(key);
				for (auto y : table[keykey].values)
				{
					if (key == y)
					{
						return keykey;
					}
				}
				break;
			case 3:
				cout << "could not found the value";
				return sizeOfTable;
				break;
			}
		}
	}
}
