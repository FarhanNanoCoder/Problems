
#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int a[], int n, int k)
{
    map<int, int> his;
    long long int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        int rem = sum - k;
        if (sum == k)
            ans = max(ans, i + 1);
        if (his.find(rem) != his.end())
        {
            ans = max(ans, i - his[rem]);
        }
        if (his.find(sum) == his.end())
        {
            his[sum] = i;
        }
    }

    return ans;
}

// only for positive numbers
int lenOfLongSubarrPos(int a[], int n, int k)
{
    long long int sum = 0;
    int ans = 0;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        sum += a[j];
        while (sum > k && j >= i)
        {
            sum -= a[i++];
        }
        if (sum == k)
            ans = max(ans, j - i + 1);
    }
    return ans;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 10;
    cout << lenOfLongSubarr(a, n, k) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
