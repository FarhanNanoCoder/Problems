#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
    int g=nums.size()-1;
    for (int i=nums.size()-2;i>=0;i--){
        if((nums[i]+i)>=g) g=i;
    }  
    return g==0;
}

int main(){
    vector<int> nums={2,3,1,1,4};
    cout<<canJump(nums);
    return 0;
}