#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int isPossible(string S)
{
    sort(S.begin(), S.end());
    int n = S.length();
    vector<int> ans;
    for (int i = 0; S[i] != '\0'; i++)
    {
        int count = 1;
        if (i < n - 1 && S[i] == S[i + 1])
        {
            count++;
            i++;
        }
        ans.push_back(count);
    }
    int count = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 1)
        {
            count++;
        }
    }
    if (count > 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    string S = "geeksogeeks";
    bool ans = isPossible(S);
    if (ans == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}