#include <iostream>

void printarray(int a[])
{
    for (auto i = 0; i < 9; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void quick_rec(int a[], int left, int right)
{
    if (left < right) // left+10 <=right i boka
    {
        int pivot = a[(left + right) / 2]; // enklere pivoteringsvalg
        int i = left, j = right;
        for (;;)
        {
            while (a[i] < pivot) { i++; } // funnet 1. fra venstre >= pivot
            while (pivot < a[j]) { j--; } // funnet 1. fra høyre <= pivot
            if (i < j)
            {
                printarray(a);
                std::swap(a[i], a[j]);   // på riktig side av pivot
            }
            else
                break;
        }
        quick_rec(a, left, i - 1);
        quick_rec(a, i + 1, right);
    }
    if (left == 0 && right == 8) printarray(a);
}

int main()
{
    int arr[9]{ 17,14,4,7,1,2,5,9,11 };

    quick_rec(arr, 0, 8);

    return 0;
}