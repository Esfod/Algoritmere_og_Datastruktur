#include <iostream>

using namespace std;

void printarray(int a[])
{
    for (auto i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
}

void quick_rec(int a[], int left, int right)//this was wrong it is suposed to be mergesort u imbasille
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
                cout << "\tleft: " << left << " right: " << right << " pivot: " << pivot << " \ti: " << i << " j: " << j << endl;
                swap(a[i], a[j]);   // på riktig side av pivot
            }
            else
                break;
        }
        quick_rec(a, left, i - 1);
        quick_rec(a, i + 1, right);
    }
    if (left == 0 && right == 8) {
        printarray(a);
        cout << endl;
    }
}

int main()
{
    int arr[14] { 17,14,5,7,12,1,16,29,13,4,8,18,22,2 };

    quick_rec(arr, 0, 8);

    return 0;
}