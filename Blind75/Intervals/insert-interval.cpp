#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    for (int i = 0; i < intervals.size(); i++)
    {
        // collision check
        if (newInterval[1] < intervals[i][0])
        {
            res.push_back(newInterval);
            while (i < intervals.size())
            {
                res.push_back(intervals[i++]);
            }
            return res;
        }
        else if (newInterval[0] > intervals[i][1])
        {
            res.push_back(intervals[i]);
        }
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    res.push_back(newInterval);
    return res;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    res = insert(intervals, newInterval);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}

// https://leetcode.com/problems/insert-interval/