#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &nums)
{
    int ans = nums[0];
    int j = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans)
        {
            j = i;
            ans = nums[i];
        }
    }
    return j;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int l = 0, r = mat.size();

    while (l <= r)
    {
        int m = (l + r) / 2;
        int p = findPeak(mat[m]);
        // cout << "max r c" << m << " " << p << endl;

        bool isPeak = true;
        if (m > 0 && mat[m - 1][p] > mat[m][p])
            isPeak = false;
        else if (m < mat.size() - 1 && mat[m + 1][p] > mat[m][p])
            isPeak = false;

        if (isPeak)
            return {m, p};
        if (m > 0 && mat[m - 1][p] > mat[m][p])
            r = m - 1;
        else
            l = m + 1;
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 6, 5}, {16, 41, 23, 22, 6}, {15, 17, 24, 21, 7}, {14, 18, 19, 20, 10}, {11, 12, 8, 7, 9}};
    vector<int> ans = findPeakGrid(mat);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}

// https://leetcode.com/problems/find-a-peak-element-ii/description/