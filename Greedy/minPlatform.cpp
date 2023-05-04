#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int size)
{
    // int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int arrPointer = 1, depPointer = 0, platforms = 1, maxPlatforms = 1;

    while (arrPointer < n && depPointer < n)
    {
        if (arr[arrPointer] > dep[depPointer])
        {
            platforms = max(--platforms, 0);
            depPointer++;
        }
        else
        {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            arrPointer++;
        }
    }
    return maxPlatforms;
}

int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800}, dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout << findPlatform(arr, dep, 6);
}

// problem_link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
