#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void kadanesAlgorithm(vector<int> &nums)
{
    int sum = 0;
    int max = nums[0];
    int start = 0, end = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (sum > max)
        {
            max = sum;
            end = i;
        }

        if (sum < 0)
        {
            sum = 0;
            if (i + 1 < nums.size())
            {
                start = i + 1;
            }
            else
            {
                start = i;
            }
        }
    }
    cout << "Maxium sum: " << max << endl;
    cout << "Subarray: [";
    for (; start < end; start++)
    {
        cout << nums[start] << ",";
    }
    cout << nums[start];
    cout << "]" << endl;
    // cout << "max: " << max << endl;
  //  cout << start << "-" << end << endl;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    kadanesAlgorithm(nums);
}

// problem link:https://leetcode.com/problems/maximum-subarray/