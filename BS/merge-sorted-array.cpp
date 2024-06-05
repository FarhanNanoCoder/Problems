#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0, k = 0;
    int total = nums1.size() + nums2.size();
    bool isEven = !(total & 1);
    int mid = total / 2;
    if (isEven)
        mid--;
    long long int t;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            t = nums1[i];
            i++;
        }
        else
        {
            t = nums2[j];
            j++;
        }
        k++;
        if (k - 1 == mid)
        {
            if (isEven)
            {
                if (i >= nums1.size())
                    t += nums2[j];
                else if (j >= nums2.size())
                    t += nums1[i];
                else
                    t += nums1[i] < nums2[j] ? nums1[i] : nums2[j];
                return t * 1.0 / 2;
            }
            return t * 1.0;
        }
    }

    while (i < nums1.size())
    {
        t = nums1[i];
        i++;
        k++;
        if (k - 1 == mid)
        {
            if (isEven)
            {
                t = t + nums1[i];
                return t * 1.0 / 2;
            }
            return t * 1.0;
        }
    }
    while (j < nums2.size())
    {
        t = nums2[j];
        j++;
        k++;
        if (k - 1 == mid)
        {
            if (isEven)
            {
                t = t + nums2[j];
                return t * 1.0 / 2;
            }
            return t * 1.0;
        }
    }
    return 1;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

// https://leetcode.com/problems/median-of-two-sorted-arrays/