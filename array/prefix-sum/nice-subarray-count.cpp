#include <bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int> &nums, int k)
{
    int c = 0, sum = 0;
    map<int, int> his;
    his[sum] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += (nums[i] & 1);
        if (his.find(sum - k) != his.end())
            c += his[sum - k];
        his[sum]++;
    }
    return c;
}

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << numberOfSubarrays(nums, k) << endl;
    return 0;
}

//https://leetcode.com/problems/count-number-of-nice-subarrays/