#include <bits/stdc++.h>
using namespace std;
int noOfBoukets(vector<int> &bloomDay, int &m, int &k, int &d)
{
    int c = 0, boukets = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {

        if (bloomDay[i] <= d)
            c++;
        else
            c = 0;
        if (c == k)
        {
            boukets++;
            c = 0;
        }
        if (boukets == m)
            return boukets;
    }
    return boukets;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int l = 1, r = bloomDay[0];
    for (int i = 0; i < bloomDay.size(); i++)
        r = max(r, bloomDay[i]);
    int ans = r;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (noOfBoukets(bloomDay, m, k, mid) < m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
            ans = mid;
        }
    }
    if (noOfBoukets(bloomDay, m, k, ans) >= m)
        return ans;

    return -1;
}

int main(){
    vector<int> bloomDay={1,10,3,10,2};
    int m=3;
    int k=1;
    cout<<minDays(bloomDay,m,k);
}

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/