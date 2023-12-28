#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> dp(n + 1, 0);
    int off = 1;
    for (int i = 1; i < n + 1; i++)
    {
        if (off * 2 == i)
            off = i;
        dp[i] = 1 + dp[i - off];
    }
    return dp;
}

int main()
{
    int n = 5;
    vector<int> res = countBits(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

//https://leetcode.com/problems/counting-bits/