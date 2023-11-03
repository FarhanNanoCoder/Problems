#include <bits/stdc++.h>
using namespace std;
int getMax(int start,int end, vector<int> & nums){
    int r1=0,r2=0,t;
    for(int i=start;i<end;i++){
      t= max(nums[i]+r1,r2);
      r1=r2;
      r2=t;
    }
    return r2;
}
int rob(vector<int> &nums)
{

    if(nums.size()==1) return nums[0];
    return max(getMax(0,nums.size()-1,nums),getMax(1,nums.size(),nums));
}

int main(){
    int n;
    cin>>n;
    vector<int> nums = {1,3,5,1,7};
    for(int &i:nums) cin>>i;
    cout<<rob(nums);
    return 0;
}