#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    int ans = INT_MAX;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[l] <= nums[m])
        {
            ans = min(nums[l], ans);
            l = m + 1;
        }
        else
        {
            ans = min(nums[m], ans);
            r = m - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    return 0;
}

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/