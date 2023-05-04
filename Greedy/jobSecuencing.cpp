#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

void printArray(int a[], int size)
{
    // int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, [](const Job &a, const Job &b)
         { return a.profit < b.profit; });

    int sequence[n];
    fill_n(sequence,n,-1);
    int maxProfit = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead - 1; j >= 0; j--)
        {
            if (sequence[j] == -1)
            {
                sequence[j] = arr[i].id;
                maxProfit += arr[i].profit;
                count++;
                break;
            }
        }
    }
    return {count,maxProfit};
}

int main()
{
    // int arr[] = {900, 940, 950, 1100, 1500, 1800}, dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    // cout << findPlatform(arr, dep, 6);
}

// problem_link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1