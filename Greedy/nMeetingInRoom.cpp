#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{

    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    if (n < 1)
        return n;
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i]});
    }
    sort(meetings.begin(), meetings.end(), comparator);
    // Your code here

    int count = 1;
    int lastEnding = meetings[0].second;
    for (int i = 1; i < n; i++)
    {
        if (lastEnding < meetings[i].first)
        {
            lastEnding = meetings[i].second;
            count++;
        }
    }
    return count;
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5}, end[] = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(start, end, 6);
}

// problem_link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
