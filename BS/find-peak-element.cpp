#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1 || nums[0] > nums[1])
        return 0;
    int l = 1, r = nums.size() - 2;
    if (nums[r + 1] > nums[r])
        return r + 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
            return m;
        if (nums[m - 1] <= nums[m])
            l = m + 1;
        else
            r = m - 1;
    }
    return 0;
}

int main(){
    vector<int> nums={1,2,3,1};
    cout<<findPeakElement(nums);
}

// https://leetcode.com/problems/find-peak-element