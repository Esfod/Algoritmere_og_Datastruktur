#pragma once
class char_stakk
{
public:
	char_stakk(const int size); //when the class gets called it will ask for an max size to make the array
	void push(const char &ch); //adds a new value at the end of the stakk
	void pop(); //removes the first value
	char top(); //returns the top value
	int size(); //returns the size
	bool empty(); //checks if the queue is empty
	char getData(int a);  //returns the data for the place in the array the number in the parameter indicates in the array
private:
	char* m_data;
	int m_top;
	int m_size;
	int m_max_size;
};

