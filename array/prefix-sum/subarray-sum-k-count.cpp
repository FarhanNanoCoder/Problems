#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    map<int, int> his;
    long long int sum = 0;
    int c = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
            c++;
        long long int rem = sum - k;
        if (his.find(rem) != his.end())
            c += his[rem];
        his[sum]++;
    }
    return c++;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << subarraySum(nums, k) << endl;
    return 0;
}


//https://leetcode.com/problems/subarray-sum-equals-k/description/
