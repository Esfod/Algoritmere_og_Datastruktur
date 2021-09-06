#pragma once
template <class T>
class temp_queue
{
public:
	temp_queue() = delete;
	temp_queue(const int& size);
	~temp_queue();
	void push(const T& a);
	void pop();
	T front();
	int size();
	bool empty();
	T getdata(int a);
private:
	T* m_data;
	int m_front;
	int m_back;
	int m_size;
	int m_max_size;
};

