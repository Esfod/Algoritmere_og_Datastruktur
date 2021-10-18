#include <iostream>
const int length{ 9 };

void printarray(int a[length])
{
	for (auto i = 0; i < length; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout<<std::endl;
}

int main()
{
	
	int a[length]{17,14,4,7,1,2,5,9,11};
	int i, hjelp, j;
	for (i = 1; i < length; i++)
	{
		hjelp = a[i];
		for (j = i-1; j>=0 && a[j]>hjelp; j--)
		{
			printarray(a);
			a[j + 1] = a[j];
			printarray(a);
		}
		a[j+1] = hjelp;
		printarray(a);
	}
	printarray(a);

	return 0;
}