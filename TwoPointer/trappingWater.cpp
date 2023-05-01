#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int trap(vector<int> &height)
{
    int leftMax = 0, rightMax = 0, l = 0, r = height.size() - 1, res = 0;

    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] >= leftMax)
                leftMax = height[l];
            else
                res += leftMax - height[l];

            l++;
        }
        else
        {
            if (height[r] >= rightMax)
                rightMax = height[r];
            else
                res += rightMax - height[r];

            r--;
        }
    }
    return res;
}
int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);
}
// problem_link: https://leetcode.com/problems/trapping-rain-water/