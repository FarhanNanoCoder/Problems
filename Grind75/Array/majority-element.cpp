#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        int res=nums[0];
        int c=1;
        int n=nums.size()/2;
        for(int i=1;i<nums.size();i++){
            if(res==nums[i]){c++;}
            else{
                c--;
                if(c<0){
                res = nums[i];
                c=1;
                }
            }
            if(c>n) return res;
        }
        return res;
}

int main(){
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
    return 0;
}