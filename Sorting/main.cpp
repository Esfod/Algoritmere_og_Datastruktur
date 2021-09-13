#include <iostream>
#include <array>
#include <chrono>
#include <algorithm>


const int array_size {10};
const int loop{ 10 };

void selection_sort(std::array<int, array_size>& a)
{
	for (auto i = 0; i < array_size; i++)
	{
		for (auto j = i + 1; j < array_size; j++)
		{
			if (a[i] > a[j])
			{
				std::swap(a[i], a[j]);
				//break;
			}
		}
	}
}

int main()
{
	std::chrono::nanoseconds avrage_time{ 0 };
	std::array<int, array_size> a_array;
	std::chrono::nanoseconds timewatch_nano{ 0 };
	
	for (auto i = 0; i < loop; i++)
	{
		
		//fills the array with random numbers
		for (auto j = 0; j < array_size; j++) { a_array[j] = rand()% 20 + 1; }

		auto start = std::chrono::high_resolution_clock::now(); //starts the counting
		//std::sort(a_array.begin(), a_array.end()); //bulit inn sort function
		selection_sort(a_array);
		auto finish = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> timewatch = finish - start;
		std::chrono::nanoseconds timewatch_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(timewatch);
		avrage_time += timewatch_nano;
	}
	avrage_time /= loop;
	// for (int i = 0; i < array_size; i++)
		//std::cout << a_array[i] << " ";
	std::cout << "\nn = " << array_size << std::endl;
	std::cout << "\nAvrage time " << avrage_time.count() << " nanoseconds" << std::endl;
	return 0;
}