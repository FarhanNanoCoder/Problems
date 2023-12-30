#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int min = 99999999;
    int max = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }
        if (prices[i] - min > max)
        {
            max = prices[i] - min;
        }
    }
    return max;
}
int main()
{
    vector<int> prices = {7,6,4,3,1};
    cout << maxProfit(prices) << endl;
}

// problem_link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/