#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

void copy_vector(vector<int> &source, vector<int> &destination, long long int n, long long int index)
{
    for (long long int i = 0; i < n; i++)
    {
        destination.push_back(source[index + i]);
    }
}

int Merge(vector<int> &nums, long long int first, long long int mid, long long int last)
{
    int pairs = 0;
    int left_size = mid - first + 1, right_size = last - mid;
    vector<int> left_sub, right_sub;

    copy_vector(nums, left_sub, left_size, first);
    copy_vector(nums, right_sub, right_size, mid + 1);

    int k=0;
    for (int i = 0; i < left_size; i++)
    {
        int cnt = 0;
        for (; k < right_size; k++)
        {
            long long int temp = (long long int)right_sub[k];
            temp *= 2;
            if (left_sub[i] > temp)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        pairs+= (left_size-i)*cnt;
    }

    int index = first;
    int i = 0, j = 0;
    while (i < left_size && j < right_size)
    {
        if (left_sub[i] <= right_sub[j])
        {
            nums[index] = left_sub[i];
            i++;
        }
        else
        {
            nums[index] = right_sub[j];
            j++;
        }
        index++;
    }
    while (i < left_size)
    {
        nums[index] = left_sub[i];
        i++;
        index++;
    }
    while (j < right_size)
    {
        nums[index] = right_sub[j];
        j++;
        index++;
    }
    return pairs;
}

int merge_sort(vector<int> &nums, long long int first, long long int last)
{
    int pairs = 0;
    if (first < last)
    {
        long long int mid = (first + last) / 2;
        pairs += merge_sort(nums, first, mid);
        pairs += merge_sort(nums, mid + 1, last);
        pairs += Merge(nums, first, mid, last);
    }
    return pairs;
}

int reversePairs(vector<int> &nums)
{
    return merge_sort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {2,4,3,5,1};
    cout << reversePairs(nums) << endl;
    // printVector(nums);
}

// problem_link: https://leetcode.com/problems/reverse-pairs/