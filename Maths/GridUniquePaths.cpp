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

// recursive solutiopn
void traverse(int i, int j, int m, int n, int &c)
{
    if (i == m - 1 && j == n - 1)
    {
        c++;
        return;
    }
    if (i < m)
    {
        traverse(i + 1, j, m, n, c);
    }
    if (j < n)
    {
        traverse(i, j + 1, m, n, c);
    }
    return;
}
// Dp approach
int countPaths(int i, int j, int m, int n, vector<vector<int>> &history)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    else if (i >= m || j >= n)
    {
        return 0;
    }
    else if (history[i][j] != -1)
    {
        return history[i][j];
    }
    else
    {
        history[i][j] = countPaths(i + 1, j, m, n, history) + countPaths(i, j + 1, m, n, history);
        return history[i][j];
    }
}

int uniquePaths(int m, int n)
{
    int c = 0;
    // traverse(0, 0, m, n, c);

    // vector<vector<int>> history;
    // for (int i = 0; i < m; i++)
    // {
    //     vector<int> temp;
    //     for (int j = 0; j < n; j++)
    //     {
    //         temp.push_back(-1);
    //     }
    //     history.push_back(temp);
    // }
    // c = countPaths(0, 0, m, n, history);
    // return c;

    int totalPaths = m + n - 2;
    int order = n - 1;
    double res = 1;
    for (int i = 1; i <= order; i++)
    {
        res = res * (totalPaths - order + i) / i;
    }
    return (int)res;
}

int main()
{
    cout << uniquePaths(3, 7);
}