#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkpalindrome(string temp)
{
    int s = 0;
    int e = temp.size() - 1;
    while (s <= e)
    {
        if (temp[s] == temp[e])
        {
            swap(temp[s], temp[e]);
            s++;
            e--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
string firstPalindrome(vector<string> &words)
{
    string ans{""};
    for (string s : words)
    {
        string temp = s;
        if (checkpalindrome(temp))
        {
            ans = s;
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<string> words = {"abc","car","ada","racecar","cool"};
    string ans = firstPalindrome(words);
    cout << ans;
    return 0;
}