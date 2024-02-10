#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

string decodeMessage(string key, string message)
{
    // create mapping
    char start = 'a';
    char mapping[275] = {0};
    for (auto ch : key)
    {
        if (ch != ' ' && mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }
    // use mapping
    string ans;
    for (auto ch : message)
    {
        if (ch == ' ')
        {
            ans.push_back(' ');
        }
        else
        {
            char decodeChar = mapping[ch];
            ans.push_back(decodeChar);
        }
    }
    return ans;
}

int main()
{
    string message = "the quick brown fox jumps over the lazy dog";
    string key = "vkbs bs t suepuv";
    string ans = decodeMessage(key, message);
    cout << ans << endl;
    return 0;
}