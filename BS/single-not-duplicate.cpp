#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (nums.size() < 2)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m - 1] != nums[m] && nums[m] != nums[m + 1])
            return nums[m];
        else if (m % 2 == 1 && nums[m] == nums[m - 1] || m % 2 == 0 && nums[m] == nums[m + 1])
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{

    vector<int> nums = {1,1,2,2,4,5,5,6,6};
    cout << singleNonDuplicate(nums);
}

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/