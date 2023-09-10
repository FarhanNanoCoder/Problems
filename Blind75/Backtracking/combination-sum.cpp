#include <bits/stdc++.h>
using namespace std;

void find(int i, int total, int target, vector<int> &candidates, vector<int> &curr, vector<vector<int>> &res)
{
    if (total == target)
    {
        res.push_back(curr);
        return;
    }
    else if (i >= candidates.size() || total > target)
    {
        return;
    }

    curr.push_back(candidates[i]);
    find(i, total + candidates[i], target, candidates, curr, res);
    curr.pop_back();
    find(i + 1, total, target, candidates, curr, res);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> curr;
    find(0, 0, target, candidates, curr, res);
    return res;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/combination-sum/