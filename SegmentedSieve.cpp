#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> Sieve(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == true)
        {
            int j = i * i;
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

vector<bool> segmentedSieve(int L, int R)
{
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> baseprime;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            baseprime.push_back(i);
        }
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 1)
    {
        segSieve[L - 1] = false;
    }
    if (L == 0)
    {
        segSieve[L] = false;
        segSieve[L + 1] = false;
    }

    for (auto prime : baseprime)
    {
        int first_mul = (L / prime) * prime;
        if (first_mul < L)
        {
            first_mul += prime;
        }
        int j = max(first_mul, prime * prime);
        while (j <= R)
        {
            segSieve[j - L] = false;
            j += prime;
        }
    }
    return segSieve;
}

int main()
{
    int L = 0;
    int R = 10;
    vector<bool> ss = segmentedSieve(L, R);
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i])
        {
            cout << i + L << " ";
        }
    }
    cout << endl;
    return 0;
}