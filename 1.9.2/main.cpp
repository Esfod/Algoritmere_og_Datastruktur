#include <iostream>
#include "TempStakk.h"

int main()
{
    //Stakk .cpp & .h for to see the class

    ADS101::TempStakk<char> cup;
    cup.push('a');
    cup.push('b');
    cup.push('c');

    std::cout << "This is the stack: ";
    cup.writeOutStack();
    std::cout << std::endl;

    std::cout << "the size of the stack is: " << cup.size() << std::endl;

    cup.pop();
    std::cout << "This is new Stack: ";
    cup.writeOutStack();
    std::cout << std::endl;
    std::cout << "the size of the stack is: " << cup.size() << std::endl;

    std::cout << "Front er :" << cup.top();

}