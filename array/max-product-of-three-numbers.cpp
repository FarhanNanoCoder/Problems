#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int l = nums.size();
    vector<int> res;
    res.push_back(nums[l - 1] * nums[l - 2] * nums[l - 3]);
    res.push_back(nums[0] * nums[1] * nums[2]);
    res.push_back(nums[0] * nums[l - 1] * nums[l - 2]);
    res.push_back(nums[0] * nums[1] * nums[l - 1]);

    sort(res.begin(), res.end());
    return res[3];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << maximumProduct(nums) << endl;
    return 0;
}


// https://leetcode.com/problems/maximum-product-of-three-numbers/description/