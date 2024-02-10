#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int garbageCollection(vector<string> &garbage, vector<int> &travel)
{
    int pickP = 0;
    int pickG = 0;
    int pickM = 0;

    int travelP = 0;
    int travelG = 0;
    int travelM = 0;

    int lastP = 0;
    int lastM = 0;
    int lastG = 0;

    for (int i = 0; i < garbage.size(); i++)
    {
        string curr = garbage[i];
        for (int j = 0; j < curr.length(); j++)
        {
            char ch = curr[j];
            if (ch == 'P')
            {
                pickP++;
                lastP = i;
            }
            if (ch == 'G')
            {
                pickG++;
                lastG = i;
            }
            if (ch == 'M')
            {
                pickM++;
                lastM = i;
            }
        }
    }
    for (int i = 0; i < lastP; i++)
    {
        travelP += travel[i];
    }
    for (int i = 0; i < lastG; i++)
    {
        travelG += travel[i];
    }
    for (int i = 0; i < lastM; i++)
    {
        travelM += travel[i];
    }

    int ans = (travelP + pickP) + (travelG + pickG) + (travelM + pickM);
    return ans;
}

int main()
{
    vector<string> garbage = {"MMM", "PGM", "GP"};
    vector<int> travel = {3, 10};
    int minimumTime = garbageCollection(garbage, travel);
    cout << minimumTime;
    return 0;
}
