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
void rotate(vector<vector<int>> &matrix)
{

    // rotate
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0 + i; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse row
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size() / 2; j++)
        {
            swap(matrix[i][j], matrix[i][matrix[0].size() - 1 - j]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(matrix);
}