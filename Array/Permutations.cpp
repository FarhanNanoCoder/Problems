#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void printVectorOfVectors(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printVector(v[i]);
        cout << endl;
    }
    cout << endl;
}

void combinations(vector<int> &nums, int start, vector<vector<int>> &res)
{
    if (start == nums.size())
    {
        res.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[start], nums[i]);
        combinations(nums, start + 1, res);
        swap(nums[start], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    combinations(nums, 0, res);
    printVectorOfVectors(res);
    cout<<res.size();

}
int main()
{
    vector<int> nums = {1};
    permute(nums);
}

// problem link: https://leetcode.com/problems/permutations/description/