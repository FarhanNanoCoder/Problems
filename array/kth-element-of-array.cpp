
#include <bits/stdc++.h>
using namespace std;
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int i = 0, j = 0, l = 0;
    int t;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            t = arr1[i++];
        }
        else
        {
            t = arr2[j++];
        }
        l++;
        if (l == k)
            return t;
    }
    while (i < n)
    {
        t = arr1[i++];
        l++;
        if (l == k)
            return t;
    }
    while (j < m)
    {
        t = arr2[j++];
        l++;
        if (l == k)
            return t;
    }
    return 1;
}

int main()
{
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;
    cout << kthElement(arr1, arr2, n, m, k);
    return 0;
}

// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array