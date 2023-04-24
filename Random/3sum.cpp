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

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res = {};
    vector<int> temp;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {

        int l = i + 1, r = nums.size() - 1;
        while (l < r)
        {
            int lr = nums[l] + nums[r] + nums[i];
            if (lr == 0)
            {
                temp.push_back(nums[i]);
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                res.push_back(temp);
                while (l < r && nums[l] == temp[1])
                    l++;
                while (l < r && nums[r] == temp[2])
                    r--;
                temp.clear();
            }
            else if (lr < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }
    return res;
}
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    printVectorOfVectors(res);
}
// problem_link: https://leetcode.com/problems/3sum/description/