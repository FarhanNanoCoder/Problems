#include <bits/stdc++.h>
using namespace std;
bool comparator(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() < 2)
        return intervals;
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), comparator);
    vector<int> prev = intervals[0];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (prev[1] >= intervals[i][0])
        {
            prev[1] = max(prev[1], intervals[i][1]);
        }
        else
        {
            res.push_back(prev);
            prev = intervals[i];
        }
    }
    res.push_back(prev);
    return res;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = merge(intervals);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}

// https://leetcode.com/problems/merge-intervals/