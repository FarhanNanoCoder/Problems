#include <bits/stdc++.h>
using namespace std;

void printVector(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i][0] << " " << v[i][1] << endl;
    }
}
// void printVector(vector<int> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
// }

bool comparator(vector<int> &v1, vector<int> &v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // sort(intervals.begin(), intervals.end(), comparator);
    sort(intervals.begin(), intervals.end());
    pair<int, int> curr = {intervals[0][0], intervals[0][1]};
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= curr.second)
        {
            if (intervals[i][1] > curr.second)
            {
                curr.second = intervals[i][1];
            }
        }
        else
        {
            res.push_back({curr.first, curr.second});
            curr.first = intervals[i][0];
            curr.second = intervals[i][1];
        }
    }
    res.push_back({curr.first, curr.second});
    return res;
}
int main()
{
    vector<vector<int>> intervals = {
        {1, 2},
        {8, 10},
        {15, 18},
        {2, 6},
    };
    merge(intervals);
}

// problem link:https://leetcode.com/problems/merge-intervals/description/