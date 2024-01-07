#include <bits/stdc++.h>
using namespace std;
bool isNum(char c)
{
    return '0' <= c && c <= '9';
}
int myAtoi(string s)
{
    int i = 0;
    while (i < s.size() && s[i] == ' ')
        i++;
    if (i == s.size())
        return 0;
    int sign = 1;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }
    if (i == s.size() || !isNum(s[i]))
        return 0;
    int ans = 0;
    while (i < s.size() && isNum(s[i]))
    {
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > 7))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        ans = ans * 10 + (s[i] - '0');
        i++;
    }
    return ans * sign;
}
int main()
{
    cout << myAtoi("  5 -42596328 56");
}