#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = 0, c = matrix[0].size() - 1;
    while (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size())
    {
        if (matrix[r][c] == target)
            return true;
        else if (target > matrix[r][c])
            r++;
        else
            c--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    cout << searchMatrix(matrix, 3) << endl;
    return 0;
}

// https://leetcode.com/problems/search-a-2d-matrix-ii/description/