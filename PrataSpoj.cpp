#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPossiblesolution(vector<int> cooksrank, int np, int mid)
{
    int currP = 0;
    for (int i = 0; i < cooksrank.size(); i++)
    {
        int R = cooksrank[i], j = 1;
        int timetaken = 0;
        while (true)
        {
            if (timetaken + R * j <= mid)
            {
                currP++;
                timetaken += R * j;
                j++;
            }
            else
            {
                break;
            }
        }
        if (currP >= np)
        {
            return true;
        }
    }
    return false;
}

int minimumTimeNeededToCookPratas(vector<int> &cooksrank, int np)
{
    int nc = cooksrank.size();
    int s = 0;
    int highsetRank = *max_element(cooksrank.begin(), cooksrank.end());
    int e = highsetRank * (np * (np + 1) / 2);
    //1r*2r*3r*4r*5r*......*nr = r(n(n+1)/2)
    int ans = 0;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossiblesolution(cooksrank, np, mid))
        //we have the solution but we will now try to decrease the time
        //so we will move left
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> cooksrank{1, 2, 3, 4};
    int np = 10;
    int minimumTime = minimumTimeNeededToCookPratas(cooksrank, np);
    cout << minimumTime << endl;
    return 0;
}