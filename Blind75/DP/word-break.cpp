#include <bits/stdc++.h>
using namespace std;
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp;
    for (int i = 0; i < s.size() + 1; i++)
    {
        dp.push_back(false);
    }
    dp[s.size()] = true;
    for (int i = s.size(); i >= 0; i--)
    {
        for (int j = 0; j < wordDict.size(); j++)
        {
            if (wordDict[j].size() <= (wordDict[j].size() + i) && wordDict[j] == s.substr(i, wordDict[j].size()))
            {
                dp[i] = dp[i + wordDict[j].size()];
            }
            if (dp[i])
            {
                break;
            }
        }
    }
    return dp[0];
}

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}