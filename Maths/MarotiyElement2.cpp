// MOORE'S ALGORITHM
#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> res = {};
    int num1 = -1, num2 = -1;

    int c1 = 0, c2 = 0;
    // Assumption
    for (int i = 0; i < nums.size(); i++)
    {
        if (num1 == nums[i])
        {
            c1++;
        }
        else if (num2 == nums[i])
        {
            c2++;
        }
        else if (c1 == 0)
        {
            num1 = nums[i];
            c1++;
        }
        else if (c2 == 0)
        {
            num2 = nums[i];
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = c2 = 0;
    cout << num1 << " " << num2 << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == num1)
        {
            c1++;
        }
        else if (nums[i] == num2)
        {
            c2++;
        }
    }
    int theshold = floor(nums.size() * 1.0 / 3);
    cout << theshold << endl;
    if (c1 > theshold)
    {
        res.push_back(num1);
    }
    if (c2 > theshold)
    {
        res.push_back(num2);
    }
    return res;
}
int main()
{
    vector<int> nums = {2,1,1,3,1,4,5,6};
    vector<int> res = majorityElement(nums);
    printVector(res);
}

// problem_link: https://leetcode.com/problems/majority-element-ii/