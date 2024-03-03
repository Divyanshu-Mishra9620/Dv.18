#include <bits/stdc++.h>
using namespace std;

static bool comp(string a, string b)
{
    return ((a + b) > (b + a));
}

string printLargest(int n, vector<string> &arr)
{
    sort(arr.begin(), arr.end(), comp);
    string ans = "";
    for (int i = 0; i < n; i++)
        ans += arr[i];
    return ans;
}
int main()
{
    vector<string> arr = {"3", "30", "34", "5", "9"};
    int n = arr.size();
    string res = printLargest(n, arr);
    cout << res;
}