#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int area = 0;
    while (l < r)
    {
        long long int temp = min(height[l], height[r]) * (r - l);
        if (temp > area)
            area = temp;
        if (height[l] < height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return area;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3};
    cout << maxArea(height);
}
// https://leetcode.com/problems/container-with-most-water/