#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int t = 0, b = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
    while (l <= r && t <= b)
    {

        for (int i = l; i <= r; i++)
        {
            res.push_back(matrix[t][i]);
        }
        t++;
        for (int i = t; i <= b; i++)
        {
            res.push_back(matrix[i][r]);
        }
        r--;
        if (t > b)
            return res;
        for (int i = r; i >= l; i--)
        {
            res.push_back(matrix[b][i]);
        }
        b--;
        if (l > r)
            return res;
        for (int i = b; i >= t; i--)
        {
            res.push_back(matrix[i][l]);
        }
        l++;
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

// https://leetcode.com/problems/spiral-matrix/