#include <bits/stdc++.h>
using namespace std;

void rotateLeft(vector<int> &nums, int k)
{
    vector<int> temp;
    k = k % nums.size();

    int r = 0;
    while (r < k)
        temp.push_back(nums[r++]);
    cout << r << endl;
    int l = 0;
    while (r < nums.size())
        nums[l++] = nums[r++];
    r = 0;
    while (r < temp.size())
        nums[l++] = temp[r++];
}

void rotateRight(vector<int> &nums, int k)
{
    vector<int> temp;
    k = k % nums.size();
    if (k == 0)
        return;

    int r = nums.size() - k;
    while (r < nums.size())
        temp.push_back(nums[r++]);
    int l = nums.size() - k - 1;
    r = nums.size() - 1;
    while (l >= 0)
        nums[r--] = nums[l--];
    r = 0;
    l=0;
    while (r < temp.size())
        nums[l++] = temp[r++];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    // rotateLeft(nums, 3);
    rotateRight(nums, 3);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << endl;

    return 0;
}