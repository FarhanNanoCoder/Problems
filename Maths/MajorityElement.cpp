// MOORE'S ALGORITHM
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int majorityElement = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            majorityElement = nums[i];
        }
        if (nums[i] == majorityElement)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return majorityElement;
}
int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout<<majorityElement(nums);
}

// problem_link: https://leetcode.com/problems/majority-element/description/