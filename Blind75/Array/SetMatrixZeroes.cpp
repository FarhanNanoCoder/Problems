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
void setZeroes(vector<vector<int>> &matrix)
{
    bool firstColShoulNotZero = true;
    bool firstRowShoulNotZero = true;
    int cols = matrix[0].size();
    int rows = matrix.size();
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColShoulNotZero = false;
            break;
        }
    }
    for (int i = 0; i < cols; i++)
    {
        if (matrix[0][i] == 0)
        {
            firstRowShoulNotZero = false;
            break;
        }
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    // printVectorOfVectors(matrix);
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            // cout << "checking for " << i << "-" << j << "|" << matrix[0][j] << "-" << matrix[i][0] << endl;
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    //    printVectorOfVectors(matrix);
    if (!firstRowShoulNotZero)
    {
        for (int i = 0; i < cols; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (!firstColShoulNotZero)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0;
        }
    }
    //  printVectorOfVectors(matrix);
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    setZeroes(matrix);
}

// problem link:https://leetcode.com/problems/set-matrix-zeroes/description/