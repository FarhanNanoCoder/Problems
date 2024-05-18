#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int n)
{
    long long int l = 1;
    long long int r = n;
    long long int ans = 1;
    while (l <= r)
    {
        long long int m = (l + r) / 2;
        if (m * m <= n)
        {
            l = m + 1;
            ans = m;
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
    cout << floorSqrt(25) << endl;
}

// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m