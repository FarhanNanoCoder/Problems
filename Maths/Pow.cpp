#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n)
{
    double ans = 1;
    long nn = n;
    if (n < 0)
    {
        nn *= -1;
    }
    while (nn)
    {
        if (nn % 2 == 0)
        {
            x = x * x;
            nn /= 2;
        }
        else
        {
            ans = ans * x;
            nn -= 1;
        }
    }
    if(n<0){
        ans = 1/ans;
    }
    return ans;
}
int main()
{
    cout << myPow(2, -1);
}

// problem_link: https://leetcode.com/problems/powx-n/description/