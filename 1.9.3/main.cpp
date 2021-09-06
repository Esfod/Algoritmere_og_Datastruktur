#include <iostream>
#include <queue>
#include "char_queue.h"
#include "temp_queue.h"


int main()
{
	/*
	std::cout << "\nChar queue\n";
	char_queue c_queue(5);
	c_queue.push('a');
	c_queue.push('b');
	c_queue.push('c');
	std::cout << "The first char is " << c_queue.front() << std::endl;
	std::cout << c_queue.getdata(2) << std::endl;
	c_queue.pop();
	std::cout << c_queue.getdata(1) << std::endl;

	std::cout << "the size of this queue is " << c_queue.size() << std::endl;
	if (c_queue.empty()) std::cout << "c_queue is empty" << std::endl;
	else if (!c_queue.empty()) std::cout << "c_queue is not empty" << std::endl;
	*/

	std::cout << "\nTemplate queue\n";
	temp_queue<char> t_queue(5);
	/*
	t_queue.push('a');
	t_queue.push('b');
	t_queue.push('c');
	std::cout << "The first varible is " << t_queue.front() << std::endl;
	t_queue.pop();
	std::cout << t_queue.getdata(2) << std::endl;
	t_queue.pop();
	std::cout << t_queue.getdata(1) << std::endl;

	std::cout << "the size of this queue is " << t_queue.size() << std::endl;
	if (t_queue.empty()) std::cout << "t_queue is empty" << std::endl;
	else if (!t_queue.empty()) std::cout << "t_queue is not empty" << std::endl;
	*/
	return 0;
}