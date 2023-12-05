#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    int rob1=0,rob2=0,t;
    for(int i=0;i<nums.size();i++){
        t = max(nums[i]+rob1,rob2);
        rob1 = rob2;
        rob2 = t;
    }
    return rob2;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums = {1,3,5,1,7};
    for (int &i : nums)
        cin >> i;
    cout << rob(nums);
    return 0;
}

// https://leetcode.com/problems/house-robber/