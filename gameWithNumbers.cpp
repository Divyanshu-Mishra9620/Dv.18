#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int *game_with_number(int arr[], int n)
{
    int i = 0;
    while (i < n - 1)
    {
        arr[i] = (arr[i] | arr[i + 1]);
        i++;
    }
    return arr;
}

int main()
{
    int arr[] = {10, 11, 1, 2, 3};
    int size = 5;
    game_with_number(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}