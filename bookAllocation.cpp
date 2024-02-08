#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
bool isPossiblesolution(int A[], int N, int M, int sol)
{
    int pagesum = 0;
    int c = 1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > sol)
        {
            return false;
        }
        if (A[i] + pagesum > sol)
        {
            c++;
            pagesum = A[i];
            if (c > M)
            {
                return false;
            }
        }
        else
        {
            pagesum += A[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if (M > N)
    {
        return -1;
    }
    int s = 0;
    int e = accumulate(A, A + N, 0);
    int ans = 0;
    int m = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossiblesolution(A, N, M, m))
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int N = 4;
    int A[] = {12, 34, 67, 90};
    int M = 2;
    int ans = findPages(A, N, M);
    cout << ans << endl;
    return 0;
}