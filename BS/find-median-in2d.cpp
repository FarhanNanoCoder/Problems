#include <bits/stdc++.h>
using namespace std;
int lowerEqualCount(vector<vector<int>> &mat, int x)
{
    int c = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        int l = 0, r = mat[i].size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (mat[i][m] > x)
                r = m - 1;
            else
                l = m + 1;
        }
        c += l;
    }
    return c;
}
int median(vector<vector<int>> &mat, int R, int C)
{
    int l = mat[0][0], r = mat[0][C - 1];
    for (int i = 0; i < mat.size(); i++)
    {
        l = min(mat[i][0], l);
        r = max(mat[i][C - 1], r);
    }
    int req = (R * C) / 2;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int c = lowerEqualCount(mat, m);
        if (c > req)
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << median(mat, 3, 3) << endl;
    return 0;
}

//https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix