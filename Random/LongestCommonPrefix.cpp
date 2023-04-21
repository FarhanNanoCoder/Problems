#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    string res = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        int j = 0;
        string temp = "";
        while (j < res.length() && strs[i].length() && res[j] == strs[i][j++])
            temp += res[j];
        if (res == "")
            return "";
        res = temp;
    }
    return res;
}
int main()
{
    vector<string> strs={"flower","flight"};
    string res = longestCommonPrefix(strs);
    cout<<res;
}
// problem_link: https://leetcode.com/problems/3sum/description/