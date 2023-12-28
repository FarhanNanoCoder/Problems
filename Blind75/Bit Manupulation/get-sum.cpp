#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b)
{
    int x;
    while (1)
    {
        x = a ^ b;
        b = (a & b) << 1;
        if (b==0)
            break;
        a = x;

    }
    return x;
}

int main()
{
    int a=2, b=3;
    cout << getSum(a, b);
    return 0;
}