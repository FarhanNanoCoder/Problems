#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l = 0, r = matrix.size() * matrix[0].size();
    int i, j, t;
    while (l <= r)
    {
        int m = (l + r) / 2;
        i = m / matrix[0].size();
        if (m == 0)
        {
            i = 0;
            j = 0;
        }
        else if (i > 0)
        {
            t = m % matrix[0].size();
            if (t > 0)
            {
                j = t - 1;
            }
            else
            {
                i = i - 1;
                j = matrix[0].size() - 1;
            }
        }
        else
        {
            j = m - 1;
        }
        if (matrix[i][j] == target)
            return true;
        if (matrix[i][j] > target)
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    cout << searchMatrix(matrix, 3) << endl;
    return 0;
}

// https://leetcode.com/problems/search-a-2d-matrix/description/