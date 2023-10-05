// C++ program to demonstrate default behaviour of
// sort() in STL.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {43, 69, 35, 37, 1, 52, 101, 10, 118, 120, 24, 68, 32, 22, 100, 29, 9, 25, 11, 66, 41, 78, 47, 36, 106, 21, 19, 91, 60, 12, 121, 85, 87, 63, 92, 107, 113, 102, 7, 71, 112, 6, 57, 44, 93, 42};
    int n = sizeof(arr) / sizeof(arr[0]);

    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    sort(arr, arr + n);

    cout << "\nTk collect from rolls : \n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    cout<<"Total given : "<<n<<endl;
    cout<<"Total : "<<n*20<<" tk"<<endl;
    return 0;
}
