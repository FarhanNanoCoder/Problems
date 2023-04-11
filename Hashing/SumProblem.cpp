#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> m;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        int remain = target - nums[i];
        if (m.find(remain) != m.end())
        {
            res.push_back(i);
            res.push_back(m[remain]);
        }
        else
        {
            m[nums[i]] = i;
        }
    }
    return res;
}
int main()
{
    vector<int> nums={2,7,11,15};
    vector<int> res = twoSum(nums,9);
    printVector(res);
}

// problem_link: https://leetcode.com/problems/two-sum/