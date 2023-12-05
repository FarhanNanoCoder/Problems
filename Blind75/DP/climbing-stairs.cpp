#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n)
{
    if (n < 3)
        return n;
    int a = 1, b = 1, c;
    while (--n)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    cout<<climbStairs(n);
    return 0;
}

// https://leetcode.com/problems/climbing-stairs/