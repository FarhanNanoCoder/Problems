#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &a, int k)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int mis = a[m] - (m + 1);
        if (mis < k)
            l = m + 1;
        else
            r = m - 1;
    }

    return l + k;
}

int main()
{
    vector<int> a = {2, 3, 4, 7, 11};
    cout << findKthPositive(a, 5);
}

// https://leetcode.com/problems/kth-missing-positive-number/