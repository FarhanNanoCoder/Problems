#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    int res = nums[0];
    while (l <= r)
    {
        if (nums[l] < nums[r])
        {
            res = min(res, nums[l]);
            break;
        }
        int mid = (l + r) / 2;
        if (nums[l] <= nums[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

int main()
{
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(a);
}