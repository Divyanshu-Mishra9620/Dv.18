#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

long long largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    // initially set i to 0 and j to last index
    long long j = nums.size() - 1;
    // polygon is with sides >= 2
    while (j >= 2)
    {
        long long i = 0;
        long long sum = 0;
        // Find sum from 0th index to j-1 to check
        // if this sum is greater than nums[j]
        while (i < j)
        {
            sum += nums[i];
            i++;
        }
        // sum is sum til (j - 1)th index.
        // Therefore for perimeter we need to add the element at jth index
        if (sum > nums[j])
        {
            return sum + nums[j];
        }
        // if sum < nums[j] i.e., largest side then no such polygon is possible
        // decrement j by 1 index and repeat again.
        else
        {
            j--;
            if (j < 2)
            {
                // no polygon with side less than 2 is possible
                return -1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> sides = {1, 12, 1, 2, 5, 50, 3};
    long long LargestPeri = largestPerimeter(sides);
    cout << LargestPeri << endl;
    return 0;
}