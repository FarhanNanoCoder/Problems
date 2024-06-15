
#include <bits/stdc++.h>
using namespace std;

void rev(vector<int> &v, int s, int e)
{
    while (s < e)
    {
        swap(v[s++], v[e--]);
    }
}
vector<int> leaders(int n, int arr[])
{
    int l = arr[n - 1];
    vector<int> res;
    res.push_back(l);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= l)
        {
            l = arr[i];
            res.push_back(l);
        }
    }
    rev(res, 0, res.size() - 1);
    return res;
    // Code here
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> res=leaders(n,arr);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}

//https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array