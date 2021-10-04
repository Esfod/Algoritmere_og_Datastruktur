#pragma once
class BinaryNode
{
public:
	BinaryNode();
	BinaryNode(int data, BinaryNode* left = nullptr, BinaryNode* right = nullptr);
	void Push(int a);
	void Pop();
	int Top();
	int Size(int a = 0);

	void PrintByLayer();



private:
	int m_data;
	BinaryNode* m_left;
	BinaryNode* m_right;

	int FindMaxHeight(BinaryNode* p);
	int FindMinHeight(BinaryNode* p);

	int FindMax(int a, int b);
	int FindMin(int a, int b);
};

