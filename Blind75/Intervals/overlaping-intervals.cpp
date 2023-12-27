#include <bits/stdc++.h>
using namespace std;
bool comparator(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() < 2)
        return 0;
    sort(intervals.begin(), intervals.end(), comparator);
    vector<int> prev=intervals[0];
    int c = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (prev[1] > intervals[i][0])
        {
            if (prev[1] > intervals[i][1])
            {
                prev = intervals[i];
            }
            c++;
        }
        else
        {
            prev = intervals[i];
        }
    }
    return c;
}
int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals);
    return 0;
}