#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int pivot = end;
    int i = start - 1;
    int j = start;
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[j], arr[i]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main()
{
    int arr[] = {7, 2, 1, 8, 6, 3, 5};
    int size = 7;
    int start = 0;
    int end = size - 1;
    quickSort(arr, start, end);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}