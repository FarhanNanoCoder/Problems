#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int m = 99999999, sum = 0, temp = 0, ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            sum = nums[i] + nums[l] + nums[r];
            temp = min(abs(sum - target), abs(target - sum));
            if (temp < m)
            {
                m = temp;
                ans = sum;
            }
            if (sum < target)
                l++;
            else
                r--;

            // while(l+1<nums.size() && nums[l]==nums[l+1]) l++;
            // while(r-1>l && nums[r]==nums[r-1]) r--;
        }
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << threeSumClosest(nums, target);
    return 0;
}

//https://leetcode.com/problems/3sum-closest/