#include <bits/stdc++.h>
using namespace std;
int longestPalindrome(string s)
{
    sort(s.begin(), s.end());
    int l = 0;
    int t;
    for (int i = 0; i < s.size(); i++)
    {
        t = 1;
        while (i + 1 < s.size() && s[i] == s[i + 1])
        {
            t++;
            i++;
            
        }
        if (t % 2 == 0)
            l += t;
        else
            l += t - 1;
    }
    if(l<s.size()) l++;
    return l;
}
int main()
{

    cout << longestPalindrome("aaab");
}