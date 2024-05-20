    #include <bits/stdc++.h>
using namespace std;
    int divSum(vector<int>& nums,int d){
        int s=0;
        for(int i =0;i<nums.size();i++){
            s += nums[i]/d + (nums[i]%d?1:0) ;
        }
        // cout<<"for "<<d<<" sum:"<<s<<endl;
        return s;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=nums[0];
        for(int i=0;i<nums.size();i++) r =max(r,nums[i]);
        int ans = r;
        while(l<r){
            int m = (l+r)/2;
            if(divSum(nums,m)>threshold){
                l=m+1;
            }else{
                r=m;
                ans=min(ans,m);
            }
        }
        return ans;
    }

    int main(){
        vector<int> nums = {1,2,5,9};
        int threshold = 6;
        cout<<smallestDivisor(nums,threshold);
    }

    // https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/