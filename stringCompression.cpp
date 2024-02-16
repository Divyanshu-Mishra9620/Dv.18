#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int compress(vector<char> &s)
{
    int index = 0;
    int prev = s[0];
    int count = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == prev)
        {
            count++;
        }
        else
        {
            s[index] = prev;
            index++;
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    s[index] = (count % 10) + '0';
                    index++;
                    count /= 10;
                }
                reverse(s.begin() + start, s.begin() + index);
            }
            prev = s[i];
            count = 1;
        }
    }
    s[index] = prev;
    index++;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            s[index] = (count % 10) + '0';
            index++;
            count /= 10;
        }
        reverse(s.begin() + start, s.begin() + index);
    }
    return index;
}

int main()
{
    vector<char> s = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int length = compress(s);
    cout << length << endl;
    return 0;
}