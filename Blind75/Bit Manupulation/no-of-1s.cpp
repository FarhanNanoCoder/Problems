#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    int c = 0;
    while (n)
    {
        c += n % 2;
        n = n >> 1;
    }
    return c;
}

int main()
{
    uint32_t n;
    cin >> n;
    cout << hammingWeight(n);
    return 0;
}