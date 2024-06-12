
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    int t;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            t = arr1[i];
            i++;
        }
        else
        {
            t = arr2[j];
            j++;
        }
        if (ans.size() == 0)
            ans.push_back(t);
        else if (t > ans.back())
        {
            ans.push_back(t);
        }
    }
    while (i < n)
    {
        if (ans.size() == 0)
            ans.push_back(arr1[i]);
        else if (arr1[i] > ans.back())
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m)
    {
        if (ans.size() == 0)
            ans.push_back(arr2[j]);
        else if (arr2[j] > ans.back())
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    int arr1[] = {1, 3, 4, 5, 7};
    int arr2[] = {2, 3, 5, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> ans = findUnion(arr1, arr2, n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays