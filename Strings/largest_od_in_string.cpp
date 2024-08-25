#include <bits/stdc++.h>
using namespace std;
bool isOdd(char c)
{
    if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9')
        return true;
    return false;
}
string largestOddNumber(string num)
{
    string res = "";
    int j = -1;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (isOdd(num[i]))
        {
            j = i;
            break;
        }
    }
    for (int i = 0; i <= j; i++)
    {
        res += num[i];
    }
    return res;
}

int main()
{
    string num = "1234567890";
    cout << largestOddNumber(num) << endl; // Output: 7531
    return 0;
}

// https://leetcode.com/problems/largest-odd-number-in-string