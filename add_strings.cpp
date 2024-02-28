#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

void add_string(string &num1, int p1, string &num2, int p2, int carry, string &ans)
{
    // base case
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }
    // processing -> 1 case mai solve krunga baki recursion sambhal lega
    int digit1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int digit2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int csum = digit1 + digit2 + carry;
    int S_digit = csum % 10;
    carry = csum / 10;
    ans.push_back(S_digit + '0');

    // recursion call
    add_string(num1, p1 - 1, num2, p2 - 1, carry, ans);
}

string addstrings(string num1, string num2)
{
    string ans = "";
    int pointer1 = num1.length() - 1;
    int pointer2 = num2.length() - 1;
    add_string(num1, pointer1, num2, pointer2, 0, ans);
    return ans;
}

int main()
{
    string num1 = "11";
    string num2 = "123";
    string sum = addstrings(num1, num2);
    reverse(sum.begin(), sum.end());
    cout << sum << endl;

    return 0;
}