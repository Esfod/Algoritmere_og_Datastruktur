#pragma once
class BinaryNode
{
public:
	BinaryNode();
	BinaryNode(char data, BinaryNode* left = nullptr, BinaryNode* right = nullptr);
	char getData();
	//void print();
	BinaryNode* find(char data);
	void insert(char data);
	void re_intrav();
	void nre_intrav();
	void nre_potrav();
	void re_potrav();
	int size();
	int hight();
private:
	char m_data;
	BinaryNode* m_left;
	BinaryNode* m_right;
};