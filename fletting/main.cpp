#include <iostream>
#include <array>
const int n = 9;

void printarray(std::array<int, n> a)
{
	for (auto i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void mergeSort(std::array<int, n> a)
{
	int i, j, k, lower1, lower2, size, upper1, upper2;
	std::array<int, n> hjelp;

	size = 1;
	while (size < n)
	{
		lower1 = 0;
		k = 0;
		while (lower1 + size < n)
		{
			upper1 = lower1 + size - 1;
			lower2 = upper1 + 1;
			upper2 = (lower2 + size - 1 < n) ? lower2 + size - 1 : n - 1;
			for (i=lower1,j=lower2;i<=upper1 && j<= upper2; k++)
			{
				if (a[i] < a[j])
					hjelp[k] = a[i++];
				else 
					hjelp[k] = a[j++];
			}
				for (; i <= upper1; k++)
					hjelp[k] = a[i++];
				for (; j <= upper2; k++)
					hjelp[k] = a[j++];
				lower1 = upper2 + 1;
		}
		for (i = lower1; k < n; i++)
			hjelp[k++] = a[i];
		for (i = 0; i < n; i++)
			a[i] = hjelp[i];
		size = size * 2;
	}
	printarray(a);
}


int main()
{
	std::array<int, n> arr{ 17,14,4,7,1,2,5,9,11 };
	mergeSort(arr);

	return 0;
}