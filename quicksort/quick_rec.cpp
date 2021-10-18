// Algoritmer og datastrukturer for spill H2019
// rekursiv quicksort - forenklet fra lærebok
/// @author Dag Nylund

#include <iostream>

void quick_rec(int a[], int left, int right)
{
    if (left < right) // left+10 <=right i boka
    {
        int pivot = a[(left+right)/2]; // enklere pivoteringsvalg
        int i=left, j=right;
        for (;;)
        {
            while (a[i] < pivot) {i++; } // funnet 1. fra venstre >= pivot
            while (pivot < a[j]) {j--; } // funnet 1. fra høyre <= pivot
            if (i<j)
                std::swap(a[i], a[j]);   // på riktig side av pivot
            else
                break;
        }
        quick_rec(a, left, i-1);
        quick_rec(a, i+1, right);
    }
}
