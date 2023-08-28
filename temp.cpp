#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {32,
                     34,
                     44,
                     13,
                     3,
                     9,
                     28,
                     7,
                     39,
                     56,
                     29,
                     57,
                     33,
                     52,
                     43,
                     41,
                     15,
                     17,
                     31,
                     4,
                     6,
                     54,
                     60,
                     49,
                     20,
                     26,
                     23,
                     24,
                     8,
                     47,
                     21,
                     16,
                     53,
                     10,
                     37,
                     5,
                     48,
                     1,
                     18,
                     11,
                     12,
                     2,
                     14, 95, 91, 113, 71, 96, 82, 81, 111, 98, 42, 36, 121, 68, 99, 86, 92, 90, 89, 85, 69, 103, 66, 100, 84, 109, 75, 97, 119, 118, 72, 88, 87, 65, 117, 73, 78, 80, 107, 76, 79, 114, 94, 105, 106, 101, 120, 46, 74, 70, 108};
    sort(a.begin(), a.end());
    // print the numbers that are not in 1-60 in the array
    int i = 0;
    int j = 1;
    int count = 0;
    while (i < a.size() && j <= 121)
    {
        if (a[i] == j)
        {
            i++;
            j++;
        }
        else
        {
            // cout << j << endl;
            count++;
            j++;
        }
    }
    cout<<count;
}