#pragma once
class char_queue
{
public:
	~char_queue();
	char_queue(const int& size);
	void push(const char& ch);
	void pop();
	char front();
	int size();
	bool empty();
private:
	char* m_data;
	int m_front;
	int m_back;
	int m_size;
	int m_max_size;
};

