#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void reverseVector(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start++], nums[end--]);
    }
}
void nextPermutation(vector<int> &nums)
{
    int increaseDroppedAt = -1;
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            increaseDroppedAt = i - 1;
            // cout << "Dropped increase at: " << increaseDroppedAt << endl;
            break;
        }
    }
    int swapAtIndex = -1;
    if (increaseDroppedAt != -1)
    {
        for (int i = nums.size() - 1; i > increaseDroppedAt; i--)
        {
            if (nums[increaseDroppedAt] < nums[i])
            {
                swapAtIndex = i;
                break;
            }
        }
        swap(nums[increaseDroppedAt], nums[swapAtIndex]);
    }
 //   printVector(nums);
    reverseVector(nums, increaseDroppedAt + 1, nums.size() - 1);
   // printVector(nums);
}
int main()
{
    vector<int> nums = {2,1};
    nextPermutation(nums);
}

// problem link: https://leetcode.com/problems/next-permutation/description/