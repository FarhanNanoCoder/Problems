#include <bits/stdc++.h>
using namespace std;

int noOfArrays(vector<int> &nums, int d)
{
    int c = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum + nums[i] <= d)
        {
            sum += nums[i];
        }
        else
        {
            c++;
            sum = nums[i];
        }
    }
    return c;
}
int splitArray(vector<int> &nums, int k)
{
    int l = 0, r = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        l = max(l, nums[i]);
        r += nums[i];
    }
    int ans = r;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (noOfArrays(nums, m) <= k)
        {
            r = m - 1;
            ans = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << splitArray(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/split-array-largest-sum/description/