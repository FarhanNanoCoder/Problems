#include <bits/stdc++.h>
using namespace std;

int noOfStudents(vector<int> &arr, int ans)
{
    
    int curr = 0;
    int students=1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (curr + arr[i] <= ans)
        {
            curr += arr[i];
        }
        else
        {
            curr = arr[i];
            students++;
        }

    }
    // cout << "for ans : " << ans << "->Students->"<<students<< endl;
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    int l = 1, r = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        l = max(l, arr[i]);
        r += arr[i];
    }
    int ans = r;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (noOfStudents(arr,mid)<=m)
        {
            r=mid-1;
            ans = mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << findPages(arr, n, m);
    return 0;
}

// problem link
// https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=PROBLEM

