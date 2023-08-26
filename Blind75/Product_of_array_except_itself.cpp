#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums;
    vector<int> res;
    long long int product = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        product *= nums[i];
        res.push_back(product);
    }
    product = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {

        if (i == nums.size() - 1)
        {
            res[i] = res[i - 1];
            product = nums[i];
        }
        else if (i == 0)
        {
            res[i] = product;
        }
        else
        {
            // cout << "i: " << i << " res[i]: " << res[i] << " product: " << product << " res[i-1]: " << res[i - 1] << endl;
            res[i] = product * res[i - 1];
            product *= nums[i];
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {2,3,4,5};
    vector<int> res = productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}