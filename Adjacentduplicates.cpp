#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

string removeDuplicates(string s)
{
    int n = s.length();
    string arr;
    int index = 0;
    while (index < n)
    {
        if (arr.length() > 0 && arr[arr.length() - 1] == s[index])
        {
            arr.pop_back();
        }
        else
        {
            arr.push_back(s[index]);
        }
        index++;
    }
    return arr;
}

int main()
{
    string s = "abbya";
    string duplicates = removeDuplicates(s);
    for (int i = 0; i < duplicates.length(); i++)
    {
        cout << duplicates[i] << " ";
    }

    return 0;
}