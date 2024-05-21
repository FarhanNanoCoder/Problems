#include <bits/stdc++.h>
using namespace std;
int daysNeed(vector<int> &weights, int cap)
{
    int s = 0;
    int d = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        int t = s + weights[i];
        if (t > cap)
        {
            d++;
            s = weights[i];
        }
        else
        {
            s += weights[i];
        }
        if (s > cap)
            return 9999999;
    }
    if (s > cap)
        return 9999999;

    return (d + 1);
}
int shipWithinDays(vector<int> &weights, int days)
{
    int l = weights[0], r = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        l = min(l, weights[i]);
        r += weights[i];
    }
    int ans = r;
    // cout<<"l : r ->"<<l<<" : "<<r<<endl;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (daysNeed(weights, m) > days)
        {
            l = m + 1;
        }
        else
        {
            r = m;
            ans = min(ans, m);
        }
    }

    return ans;
}

int main(){

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout<<shipWithinDays(weights,days);
}

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/