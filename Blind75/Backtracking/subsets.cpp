#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res, int start)
{
    res.push_back(curr);
    for (int i = start; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);
        dfs(nums, curr, res, i + 1);
        curr.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> curr;
    vector<vector<int>> res;
    dfs(nums, curr, res, 0);
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ", ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/subsets/