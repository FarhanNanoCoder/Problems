
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int l = nums.size();
    vector<int> res(l);
    int p = 0, n = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            res[2 * p] = nums[i];
            p++;
        }
        else
        {
            res[2 * n + 1] = nums[i];
            n++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    vector<int> res = rearrangeArray(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

//https://leetcode.com/problems/rearrange-array-elements-by-sign/description/