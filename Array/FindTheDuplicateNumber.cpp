#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void printMap(map<int, int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

int findDuplicate(vector<int> &nums)
{
    map<int, int> counts;
    for (int i = 0; i < nums.size(); i++)
    {
        counts[nums[i]] = ++counts[nums[i]];
    }
    for(auto it=counts.begin();it!=counts.end();it++){
        if(it->second >1){
            return it->first;
        }
    }
}

int main()
{
    vector<int> nums = {1,3,4,2,2};
    cout<<findDuplicate(nums);
}