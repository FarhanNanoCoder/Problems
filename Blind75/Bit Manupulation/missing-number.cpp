#include <bits/stdc++.h>
using namespace std;

// int missingNumber(vector<int> &nums)
// {
//     long long int sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum = sum + nums[i];
//     }
//     sum = (nums.size() * (nums.size() + 1) / 2) - sum;
//     return sum;
// }

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ i ^ nums[i];
    }
    return res ^ n;
}

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(nums);
    return 0;
}