
#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int x = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        x = x ^ nums[i] ^ i + 1;
    }
    return x;
}

int main()
{
    vector<int> nums = {0, 1, 3};
    cout << missingNumber(nums);
    return 0;
}

//https://leetcode.com/problems/missing-number/description/