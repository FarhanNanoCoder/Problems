#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int longestConsecutive(vector<int> &nums)
{
    map<int, int> numHash;
    int length = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        numHash.insert({nums[i], nums[i]});
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (numHash.find(nums[i] - 1) == numHash.end())
        {
            int temp = 0;
            while (numHash.find(nums[i] + temp) != numHash.end())
            {
                temp++;
            }
            if (temp > length)
                length = temp;
        }
    }
    return length;
}
int main()
{
    vector<int> nums = {};
    cout << longestConsecutive(nums);
}