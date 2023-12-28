#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums){
	int maxProduct=1;
	int minProduct=1;
	int temp;
	int res=-9999999;
	for(int i=0;i<nums.size();i++){
		res = max(res, nums[i]);
		if(nums[i]==0){
			maxProduct=1;
			minProduct=1;
			continue;
		}
		temp = maxProduct*nums[i];
		maxProduct = max(nums[i], minProduct*nums[i]);
		maxProduct = max(maxProduct, temp);

		minProduct = min(nums[i], minProduct*nums[i]);
		minProduct = min(minProduct,temp);

		res=max(res,maxProduct);
	}
	return res;
}
int main(){
	vector<int> nums={1,2,3,-4,-5};
	cout<<maxProduct(nums);
}

//https://leetcode.com/problems/maximum-product-subarray/