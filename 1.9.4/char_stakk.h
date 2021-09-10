#pragma once
class char_stakk
{
public:
	char_stakk(const int size);
	void push(const char &ch);
	void pop();
	char top();
	int size();
	bool empty();
	char getData(int a);
private:
	char* m_data;
	int m_top;
	int m_size;
	int m_max_size;
};

