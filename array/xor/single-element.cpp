#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int x = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        x = x ^ nums[i];
    }
    return x;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << singleNumber(nums) << endl;
    return 0;
}

//https://leetcode.com/problems/single-number/description/