#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.size();
    else
    {
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
}
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums);
}
// problem_link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/