#include <bits/stdc++.h>
using namespace std;
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    vector<pair<int, int>> jobs;
    for (int i = 0; i < difficulty.size(); i++)
        jobs.push_back({difficulty[i], profit[i]});
    sort(jobs.begin(), jobs.end());

    sort(worker.begin(), worker.end());

    vector<int> maxProfitAtDifficulty(difficulty.size());
    maxProfitAtDifficulty[0] = jobs[0].second;
    for (int i = 1; i < jobs.size(); i++)
        maxProfitAtDifficulty[i] = max(maxProfitAtDifficulty[i - 1], jobs[i].second);

    long long int ans = 0;
    int j = 0;

    for (int i = 0; i < worker.size(); i++)
    {
        while (j < jobs.size() && worker[i] >= jobs[j].first)
            j++;
        if (j > 0)
            ans += maxProfitAtDifficulty[j - 1];
    }

    return ans;
}

int main()
{
    vector<int> difficulty = {66, 1, 28, 73, 53, 35, 45, 60, 100, 44, 59, 94, 27, 88, 7, 18, 83, 18, 72, 63};
    vector<int> profit = {66, 20, 84, 81, 56, 40, 37, 82, 53, 45, 43, 96, 67, 27, 12, 54, 98, 19, 47, 77};
    vector<int> worker = {61, 33, 68, 38, 63, 45, 1, 10, 53, 23, 66, 70, 14, 51, 94, 18, 28, 78, 100, 16};
    // vector<int> difficulty = {2, 4, 6, 8, 10};
    // vector<int> profit = {10, 20, 30, 40, 50};
    // vector<int> worker = {4, 5, 6, 7};
    cout << maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}

//https://leetcode.com/problems/most-profit-assigning-work/description/