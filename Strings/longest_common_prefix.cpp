#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string res = "";
    int j = 0;
    while (1)
    {
        if (j >= strs[0].size())
            return res;
        char c = strs[0][j];
        for (int i = 1; i < strs.size(); i++)
        {
            if (j >= strs[i].size() || strs[i][j] != c)
            {
                return res;
            }
        }
        res += c;
        j++;
    }
    return res;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl; // Output: "fl"
    return 0;
}

// https://leetcode.com/problems/longest-common-prefix/description/