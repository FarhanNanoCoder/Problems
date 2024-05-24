#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &stalls, int k, int d)
{
    k--;
    int lastPlaced = 0;
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - stalls[lastPlaced] >= d)
        {
            lastPlaced = i;
            k--;
        }
        if (k == 0)
            return true;
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int l = 1, r = max(1, stalls[n - 1] - stalls[0]);
    int ans = 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (possible(stalls, k, m))
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }
    cout << solve(n, k, stalls);
    return 0;
}


// problemLink
// https://www.geeksforgeeks.org/problems/aggressive-cows
