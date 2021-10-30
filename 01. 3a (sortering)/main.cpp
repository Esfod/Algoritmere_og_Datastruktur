#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

const int ten_vector_size{ 10 };
const int hundred_vector_size{ 100 };
const int thousand_vector_size{ 1000 };
const int tenthousand_vector_size{ 10000 };

vector<int> tenvector;
vector<int> hundredvector;
vector<int> thousandvector;
vector<int> tenthousandvector;

const int loops{ 10 };

void fillVector()
{
	int j = 0;
	tenvector.clear();
	hundredvector.clear();
	thousandvector.clear();
	tenthousandvector.clear();

	while (j < ten_vector_size) {
		tenvector.push_back( rand() % ten_vector_size + 1);
		j++;
	}

	j = 0;
	while (j < hundred_vector_size) {
		hundredvector.push_back(rand() % hundred_vector_size + 1);
		j++;
	}

	j = 0;
	while (j < thousand_vector_size) {
		thousandvector.push_back(rand() % thousand_vector_size + 1);
		j++;
	}

	j = 0;
	while (j < tenthousand_vector_size) {
		tenthousandvector.push_back(rand() % tenthousand_vector_size + 1);
		j++;
	}
}

void insertionSort(vector<int> a)
{
	int i, hjelp, j;
	for ( i = 1; i < a.size(); i++)
	{
		hjelp = a[i];
		for ( j = i - 1; j >= 0 && a[j] > hjelp; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = hjelp;
	}
}

void mergeSort(vector<int> a)
{
	int i, j, k, lower1, lower2, size, upper1, upper2;
	auto n = a.size();
	vector<int> hjelp;
	for (size_t i = 0; i < n; i++)
	{
		hjelp.push_back(0);
	}

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
			for (i = lower1, j = lower2; i <= upper1 && j <= upper2; k++)
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
}

void takeTimeInsertionSort(vector<int> a)
{
	chrono::nanoseconds average_time{ 0 };
	chrono::nanoseconds timewatch_nano{ 0 };
	for (auto i = 0; i < loops; i++)
	{
		auto start = std::chrono::high_resolution_clock::now(); //starts the counting
		insertionSort(a);
		auto finish = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> timewatch = finish - start;
		std::chrono::nanoseconds timewatch_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(timewatch);
		average_time += timewatch_nano;
	}
	average_time /= loops;
	std::cout << "\nn = " << a.size() << " Average time " << average_time.count() << " nanoseconds" << std::endl;
}

void takeTimeMergeSort(vector<int> a)
{
	chrono::nanoseconds average_time{ 0 };
	chrono::nanoseconds timewatch_nano{ 0 };
	for (auto i = 0; i < loops; i++)
	{
		auto start = std::chrono::high_resolution_clock::now(); //starts the counting
		mergeSort(a);
		auto finish = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double> timewatch = finish - start;
		std::chrono::nanoseconds timewatch_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(timewatch);
		average_time += timewatch_nano;
	}
	average_time /= loops;
	std::cout << "\nn = " << a.size() << " Average time " << average_time.count() << " nanoseconds" << std::endl;
}


int main()
{
	fillVector();
	cout << "\tInsertionSort\t" << endl;
	takeTimeInsertionSort(tenvector);
	takeTimeInsertionSort(hundredvector);
	takeTimeInsertionSort(thousandvector);
	takeTimeInsertionSort(tenthousandvector);
	cout << "\n\tMergeSort\t" << endl;
	fillVector();
	takeTimeMergeSort(tenvector);
	takeTimeMergeSort(hundredvector);
	takeTimeMergeSort(thousandvector);
	takeTimeMergeSort(tenthousandvector);
	return 0;
}