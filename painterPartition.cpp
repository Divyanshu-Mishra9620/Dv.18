#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool possiblesolution(int A[], int n, int k, long long sol)
{
    long long timesum = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > sol)
        {
            return false;
        }
        if (A[i] + timesum > sol)
        {
            c++;
            timesum = A[i];
            if (c > k)
            {
                return false;
            }
        }
        else
        {
            timesum += A[i];
        }
    }
    return true;
}
long long minTime(int arr[], int n, int k)
{
    long long s = 0;
    long long e = 0;
    for (int i = 0; i < n; i++)
    {
        e += arr[i];
    }
    long long mid = s + (e - s) / 2;
    long long ans = -1;
    while (s <= e)
    {
        if (possiblesolution(arr, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int n = 5;
    int k = 3;
    int arr[] = {5, 10, 30, 20, 15};
    int ans = minTime(arr, n, k);
    cout << ans;
    return 0;
}