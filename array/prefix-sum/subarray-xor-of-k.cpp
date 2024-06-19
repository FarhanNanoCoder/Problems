#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int k) {
    map<int,int> his;
    long long int sum=0;
    int c=0;
    for(int i=0;i<nums.size();i++){
        sum=sum^nums[i];
        if(sum==k) c++;
        long long int rem = sum^k;
        if(his.find(rem)!=his.end()) c+=his[rem];
        his[sum]++;;
    }
    return c++;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    cout<<solve(nums,k)<<endl;
    return 0;
}