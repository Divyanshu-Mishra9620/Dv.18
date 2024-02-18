#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

string convert(string s, int numRows)
{
    vector<string> ans(numRows);
    if (numRows == 1) return s;
    int i = 0;
    int direction = 1;
    int row = 0;
    while (i < s.size())
    {
        if (direction == 1)
        {
            while (i < s.size() && row < numRows)
            {
                ans[row].push_back(s[i]);
                row++;
                i++;
            }
            direction = -1;
            row = numRows - 2;
        }
        else
        {
            while (i < s.size() && row >= 0)
            {
                ans[row].push_back(s[i]);
                row--;
                i++;
            }
            direction = 1;
            row = 1;
        }
    }
    string ansString = "";
    for (int i = 0; i < numRows; i++)
    {
        ansString = ansString + ans[i];
    }
    return ansString;
}

int main()
{
    string input = "PAYPALISHIRING";
    int rows = 3;
    string ZigZag = convert(input, rows);
    cout << ZigZag;
    
    return 0;
}