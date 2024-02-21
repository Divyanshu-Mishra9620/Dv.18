#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
/*You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security
system connected, and it will automatically contact the police if two adjacent houses were broken into
on the same night.*/
int solve(vector<int> &nums, int s, int e)
{
    if (s > e)
    {
        return 0;
    }
    int option1 = nums[s] + solve(nums, s + 2, e);
    int option2 = 0 + solve(nums, s + 1, e);
    int finalans = max(option1, option2);
    return finalans;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    int option1 = solve(nums, 0, n - 2);
    int option2 = solve(nums, 1, n - 1);
    int ans = max(option1, option2);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int totalCoins = rob(nums);
    cout << totalCoins << endl;
    return 0;
}