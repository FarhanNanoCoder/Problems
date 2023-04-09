#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void printVectorOfVectors(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printVector(v[i]);
        cout << endl;
    }
    cout << endl;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int col = matrix[0].size();
    for (int i = 0; i < matrix.size(); i++)
    {
        // is in the row range
        if (matrix[i][0] <= target && matrix[i][col - 1] >= target)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        // {10, 11, 16, 20},
        // {23, 30, 34, 60}
        };
    cout << searchMatrix(matrix, 3);
}

// problem_link: https://leetcode.com/problems/search-a-2d-matrix/