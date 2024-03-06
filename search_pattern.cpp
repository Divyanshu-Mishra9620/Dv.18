#include <bits/stdc++.h>
using namespace std;

vector<int> search(string pattern, string text)
{
    vector<int> ans;
    int found = text.find(pattern);
    while (found != string::npos)
    {
        ans.push_back(found + 1);
        found = text.find(pattern, found + 1);
    }
    return ans;
}

int main()
{
    string text = "birthdayboybirth";
    string pattern = "birth";
    vector<int> res = search(pattern, text);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}