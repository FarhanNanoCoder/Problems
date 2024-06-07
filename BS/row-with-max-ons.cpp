
#include <bits/stdc++.h>
using namespace std;
int oneCount(vector<int> &arr)
{
    int l = 0, r = arr.size() - 1;
    if (arr[r] == 0)
        return 0;
    if (arr[l] == 1)
        return r + 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == 1 && arr[m - 1] == 0)
            return arr.size() - m;
        if (m + 1 < arr.size() && arr[m] == 0 && arr[m + 1] == 1)
            return arr.size() - m - 1;
        if (arr[m] < 1)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
}
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    int ans = 0, t;
    int ind = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        t = oneCount(arr[i]);
        if (t > ans)
        {
            ans = t;
            ind = i;
        }
    }
    return ans > 0 ? ind : -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << rowWithMax1s(arr, n, m) << endl;
    }
    return 0;
}

// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s