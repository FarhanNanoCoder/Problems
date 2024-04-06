#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[l] == nums[mid] && nums[mid] == nums[r])
        {
            l++;
            r--;
        }
        else if (nums[l] <= nums[mid])
        {
            if (target >= nums[l] && target < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid] && target <= nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return false;
}

int main()
{

    vector<int> nums={2,5,6,0,0,1,2};
    cout<<search(nums,0);
}

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/