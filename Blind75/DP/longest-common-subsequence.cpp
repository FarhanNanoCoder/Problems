#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    const int n = text2.length() + 1;
    const int m = text1.length() + 1;
    int dp[m][n];
    for (int i = 0; i < n; i++)
    {
        dp[m - 1][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        dp[i][n - 1] = 0;
    }
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}
int main()
{
    string text1, text2;
    cin >> text1 >> text2;
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}