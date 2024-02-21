/*Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array
bank representing the floor plan of the bank, which is an m x n 2D matrix. 
bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty,
while'1' means the cell has a security device.
-->There is one laser beam between any two security devices if both conditions are met:
1) The two devices are located on two different rows: r1 and r2, where r1 < r2.
2) For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.
->Return the total number of laser beams in the bank.*/
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

string reorganizeString(string s)
{
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a']++;
    }
    char max_freq_char;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }
    int index = 0;
    while (max_freq > 0 && index < s.size())
    {
        {
            s[index] = max_freq_char;
            index += 2;
            max_freq--;
        }
    }
    if (max_freq != 0)
    {
        return "";
    }
    hash[max_freq_char - 'a'] = 0;
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index > s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    return s;
}

int main()
{
    string s = "aaabb";
    string s1 = reorganizeString(s);
    cout << s1;

    return 0;
}