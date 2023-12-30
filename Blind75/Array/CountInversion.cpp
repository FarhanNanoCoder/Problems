#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void copy_array(long long int *source, long long int *destination, long long int n, long long int index)
{
    for (long long int i = 0; i < n; i++)
    {
        *(destination + i) = *(source + index + i);
    }
}
long long int Merge(long long int a[], long long int first, long long int mid, long long int last)
{
    long long int inversions = 0;
    long long int left_size = mid - first + 1, right_size = last - mid;
    long long int left_sub[left_size], right_sub[right_size];

    copy_array(a, left_sub, left_size, first);
    copy_array(a, right_sub, right_size, mid + 1);

    long long int index = first;
    long long int i = 0, j = 0;
    while (i < left_size && j < right_size)
    {
        if (left_sub[i] <= right_sub[j])
        {
            a[index] = left_sub[i];
            i++;
        }
        else
        {
            a[index] = right_sub[j];
            j++;
            inversions += (left_size-i);
        }
        index++;
    }
    while (i < left_size)
    {
        a[index] = left_sub[i];
        i++;
        index++;
    }
    while (j < right_size)
    {
        a[index] = right_sub[j];
        j++;
        index++;
    }
    return inversions;
}
long long int merge_sort(long long int a[], long long int first, long long int last)
{
    long long int inversions = 0;
    if (first < last)
    {
        long long int mid = (first + last) / 2;
        inversions += merge_sort(a, first, mid);
        inversions += merge_sort(a, mid + 1, last);
        inversions += Merge(a, first, mid, last);
    }
    return inversions;
}

long long int inversionCount(long long arr[], long long N)
{
    return merge_sort(arr, 0, N - 1);
}

int main()
{
    long long int arr[] = {2, 3, 4, 5, 6};
    cout << inversionCount(arr, 5);
}

// problem_link:https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1