#include <iostream>
#include "char_stakk.h"
#include "temp_stakk.h"

int main()
{
	std::cout << "\nchar_Stakk\n";
	char_stakk c_stakk(6);
	c_stakk.push('a');
	c_stakk.push('b');
	c_stakk.push('c');
	for (auto i = 0; i < c_stakk.size(); i++)
	{
		std::cout << c_stakk.getData(i) << ' ';
	}
	std::cout << std::endl;
	c_stakk.pop();
	for (auto i = 0; i < c_stakk.size(); i++)
	{
		std::cout << c_stakk.getData(i) << ' ';
	}
	std::cout << std::endl;
	std::cout << "The size of c_stakk is " << c_stakk.size() << std::endl;

	std::cout << "\ntemp_Stakk\n";
	temp_stakk<char> t_stakk(4);
	t_stakk.push('a');
	t_stakk.push('b');
	t_stakk.push('c');
	for (auto i = 0; i < t_stakk.size(); i++)
	{
		std::cout << t_stakk.getData(i) << ' ';
	}
	std::cout << std::endl;
	t_stakk.pop();
	for (auto i = 0; i < t_stakk.size(); i++)
	{
		std::cout << t_stakk.getData(i) << ' ';
	}
	std::cout << std::endl;
	std::cout << "The size of c_stakk is " << t_stakk.size() << std::endl;
}