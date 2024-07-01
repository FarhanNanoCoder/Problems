
#include <bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int> arr, int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
        a = a ^ arr[i] ^ (i + 1);

    a = (a & ~(a - 1));

    int zero = 0;
    int one = 0;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & a) != 0)
            one = one ^ arr[i];
        else
            zero = zero ^ arr[i];

        if (((i + 1) & a) != 0)
            one = one ^ (i + 1);
        else
            zero = zero ^ (i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == one)
            return {one, zero};
    }
    return {zero, one};
}

int main()
{
    vector<int> arr = {1, 3, 3};
    int n = arr.size();

    vector<int> result = findTwoElement(arr, n);
    cout << "The two elements are: " << result[0] << " and " << result[1] << endl;
}

//https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating        
