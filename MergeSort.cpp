#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int lenleft = mid - s + 1;
    int lenright = e - mid;

    // create left and right array
    int *left = new int[lenleft];
    int *right = new int[lenright];

    // copy values from original array to left array
    // k-> starting index of left array values in main array
    int k = s;
    for (int i = 0; i < lenleft; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy values from original array to right array
    // k-> starting index of right array values in main array
    k = mid + 1;
    for (int i = 0; i < lenright; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // actual merge sort logic
    // left and right array is sorted by recursion
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s; // yha pr log glti krte h , index = s not 0

    while (leftIndex < lenleft && rightIndex < lenright)
    {
        // if element of left array is samaller
        if (left[leftIndex] > right[rightIndex])
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
        // if element of right array is smaller
        else
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
    }

    // Case 1 -> right array is exhausted pr left array me elemnts abhi bhi bche hue h
    while (leftIndex < lenleft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    // Case 2 -> left array is exhausted pr right array me elemnts abhi bhi bche hue h
    while (rightIndex < lenright)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // deallocate the memory
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    // recursive call for left array
    mergeSort(arr, s, mid);

    // recursive call for right array
    mergeSort(arr, mid + 1, e);

    // merge 2 sorted array
    merge(arr, s, e);
}

int main()
{
    int arr[] = {20, 60, 55, 15, 45, 30, 72};
    int size = 7;
    int s = 0;
    int e = size - 1;
    mergeSort(arr, s, e);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}