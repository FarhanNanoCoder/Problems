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

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res = {};
    vector<int> temp;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int l = j + 1, r = nums.size() - 1;
            long long int remaining = (long long int)target - (long long int)(nums[i] + nums[j]);
            while (l < r)
            {
                int lr = nums[l] + nums[r];
                if (lr == remaining)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    while (l < r && nums[l] == temp[2])
                        l++;
                    while (l < r && nums[r] == temp[3])
                        r--;
                    temp.clear();
                }
                else if (lr < remaining)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            while (j + 1 < nums.size() - 2 && nums[j + 1] == nums[j])
                j++;
        }
        while (i + 1 < nums.size() - 3 && nums[i + 1] == nums[i])
            i++;
    }
    return res;
}
int main()
{
    vector<int> nums = {0};
    vector<vector<int>> res = fourSum(nums, 0);
    printVectorOfVectors(res);
}

// problem_link: https://leetcode.com/problems/4sum/