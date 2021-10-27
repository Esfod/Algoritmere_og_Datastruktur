#include "hash.h"

int hashTable::hashFunction(string key)
{
	int delta{ 0 };
	for (int i{0}; i < key.size(); i++)
	{
		delta += key[i];
	}
	return delta % hashListLenght;
}

int hashTable::reHash(string key)
{
	return 0;
}

void hashTable::insert(string value)
{
	int hashValue{ hashFunction(value) };
	if(IsQueueFull(hashValue));
	{
		hashValue = reHash(value);
		if (IsQueueFull(hashValue));
		{
			cout << "full" << endl;
		}
	}


}

void hashTable::remove(int key)
{

}

bool hashTable::IsEmpty() const
{
	string sum{ 0 };
	for (int i = 0; i < table.size(); i++)
	{
		for (int k = 0; k < table[i].size(); k++)
		{
			sum += table[i][k].second;
		}
	}
	if (sum!="")
		return true;
	return false;
}

bool hashTable::IsQueueFull(int key)
{
	int delta{ 0 };
	for (int i = 0; i < table[key].size(); i++)
	{
		if (table[key][i].second != "")
			delta++;
		else return false;
	}
	if (delta == hashListHeight)
		return true;
	return false;
}

void hashTable::PrintTable()
{
}

void hashTable::Find(int key)
{
}
