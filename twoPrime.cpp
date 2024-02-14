#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
// returning prime whose sum is N
// first prime should be minimum that is possible

vector<bool> Sieve(int n)
{
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= n; i++)
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
vector<int> primeDivision(int N)
{
    vector<int> ans;
    vector<int> ans1;
    vector<bool> primes = Sieve(N);
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i])
        {
            ans.push_back(i);
        }
    }
    int s = 0;
    int e = ans.size() - 1;
    while (s <= e)
    {
        if (ans[s] + ans[e] == N)
        {
            ans1.push_back(ans[s]);
            ans1.push_back(ans[e]);
            return ans1;
        }
        else if (ans[s] + ans[e] > N)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    return ans1;
}

int main()
{
    vector<int> ans = primeDivision(74);
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {

        sum += ans[i];
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}