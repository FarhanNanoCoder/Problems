#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> freq;
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
    }
    vector<pair<int, int>> v;
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        v.push_back(make_pair(it->first, it->second));
    }
    sort(v.begin(), v.end(), comparator);
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(v[i].first);
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

}

// https://leetcode.com/problems/top-k-frequent-elements/