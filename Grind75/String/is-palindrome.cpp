#include <bits/stdc++.h>
using namespace std;
bool isAlpha(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
        return true;
    return false;
}
bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        while (!isAlpha(s[l]) && l < r) l++;
 
        while (!isAlpha(s[r]) && l < r) r--;
        if (l >= r)
            break;
        if (s[l] <= 'Z')
            s[l] += 32;
        if (s[r] <= 'Z')
            s[r] += 32;
        if (s[l] != s[r])  return false;

        l++;
        r--;
    }
    return true;
}
int main()
{
    // cout << isPalindrome("A man, a plan, a canal: Panama");
    cout << isPalindrome("0L");
}