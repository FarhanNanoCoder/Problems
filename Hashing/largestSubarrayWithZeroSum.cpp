#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int maxLen(vector<int> &nums, int n)
{
    map<long long int, int> sums;
    long long int sum = 0;
    int length = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == 0)
        {
            length = max(length, i + 1);
        }
        else if (sums.find(sum) != sums.end())
        {
            length = max(i-sums[sum] , length);
        }
        else
        {
            sums.insert({sum, i});
        }
    }
    return length;
}
int main()
{
    vector<int> nums = {15,-2,2,-8,1,7,10,23};
    cout << maxLen(nums, nums.size());
}