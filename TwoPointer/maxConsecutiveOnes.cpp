#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void printVectorOfVectors(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printVector(v[i]);
        cout << endl;
    }
    cout << endl;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            count++;
        else
        {
            res = max(count, res);
            count = 0;
        }
    }
    res = max(count, res);
    return res;
}
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums);
}
// problem_link: https://leetcode.com/problems/max-consecutive-ones/