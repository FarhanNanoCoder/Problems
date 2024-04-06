#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> nums, int target)
{
    int lb = nums.size();
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = (l + r )/ 2;
        if (nums[m] >= target)
        {
            r = m - 1;
            lb = m;
        }
        else
        {
            l = m + 1;
        }
        // cout << "l-r" << l << "" << r << endl;
    }
    return lb;
}
int upperBound(vector<int> nums, int target)
{
    int lb = nums.size();
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = (l + r )/ 2;
        if (nums[m] > target)
        {
            r = m - 1;
            lb = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return lb;
}
int floor(vector<int> nums, int target){
    int l=0,r=nums.size()-1;
    int f=-1;
    while(l<=r){
        int m= (l+r)/2;
        if(nums[m]<=target){
            f=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return f;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 6, 6, 6, 6, 7, 8};
    cout << lowerBound(nums, 5) << endl;
    cout<<upperBound(nums,6)<<endl;
    cout<<floor(nums,-1)<<endl;
}