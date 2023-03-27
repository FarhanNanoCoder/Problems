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

// REQUIRES EXTRA SPACE O(N1+N2), TIME COMPLEXITY O(2(N1+N2))
void timeOptimalTechnique(int a[], int b[], int n1, int n2)
{
    int c[n1 + n2];
    int i = 0, j = 0, k = 0;
    while (i < n1 || j < n2)
    {
        cout << "came here" << endl;
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
            // insert from  remaining array
            if (i == n1)
            {
                while (j < n2)
                {
                    c[k++] = b[j++];
                }
            }
        }
        else
        {
            c[k++] = b[j++];
            // insert from  remaining array
            if (j == n2)
            {
                while (i < n1)
                {
                    c[k++] = a[i++];
                }
            }
        }
    }
    i = 0, j = 0, k = 0;
    while (i < n1)
    {
        a[i++] = c[k++];
    }
    while (j < n2)
    {
        b[j++] = c[k++];
    }
    printArray(c, n1 + n2);
    printArray(a, n1);
    printArray(b, n2);
}

void spaceOptimalTechnique(int a[], int b[], int n1, int n2)
{
    if (n1 >= n2)
    {
        for (int i = 0; i < n1; i++)
        {
            if (a[i] > b[0])
            {
                swap(a[i], b[0]);
                sort(b, b + n2);
            }
        }
    }
    else
    {
        for (int i = 0; i < n2; i++)
        {
            if (b[i] > a[0])
            {
                swap(b[i], a[0]);
                sort(a, a + n1);
            }
        }
    }
    printArray(a, n1);
    printArray(b, n2);
}

// MOST EFFITIENT
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int a[], int b[], int n1, int n2)
{
    int gap = n1 + n2, total = n1 + n2;
    while (gap = nextGap(gap))
    {
        int i = 0;
        int j = i + gap;
        while (j < total)
        {
            if (i < n1 && j < n1)
            {
                if (a[i] > a[j])
                    swap(a[i], a[j]);
            }
            else if (i < n1 && j >= n1)
            {
                if (a[i] > b[j - n1])
                    swap(a[i], b[j - n1]);
            }
            else if (i >= n1 && j >= n1)
            {
                if (b[i - n1] > b[j - n1])
                    swap(b[i - n1], b[j - n1]);
            }
            i++;
            j++;
        }
    }
    printArray(a, n1);
    printArray(b, n2);
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int gap = m + n, total = m + n;
    while (gap = nextGap(gap))
    {
        int i = 0;
        int j = i + gap;
        while (j < total)
        {
            if (i < m && j < m)
            {
                if (nums1[i] > nums1[j])
                    swap(nums1[i], nums1[j]);
            }
            else if (i < m && j >= m)
            {
                if (nums1[i] > nums2[j - m])
                    swap(nums1[i], nums2[j - m]);
            }
            else if (i >= m && j >= m)
            {
                if (nums2[i - m] > nums2[j - m])
                    swap(nums2[i - m], nums2[j - m]);
            }
            i++;
            j++;
        }
    }
}
int main()
{
    int a[] = {2, 4, 6, 7};
    int b[] = {1, 3, 5};
    // timeOptimalTechnique(a, b, 4, 3);
    // spaceOptimalTechnique(b, a, 3, 4);
    merge(a, b, 4, 3);
}