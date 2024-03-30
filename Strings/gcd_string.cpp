#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n)
{
    while (m != n)
    {
        if (m > n)
            m -= n;
        else
            n -= m;
    }
    return m;
}
string gcdOfStrings(string str1, string str2)
{
    int n = gcd(str1.size(), str2.size());
    for (int i = 0; i < str1.size(); i++)
    {
        if (i < str2.size() && str2[i] != str2[i % n])
            return "";
        if (str1[i] != str2[i % n])
            return "";
    }
    return str2.substr(0, n);
}

int main()
{
    string str1 = "ABCABC", str2 = "ABC";
    cout << gcdOfStrings(str1, str2) << endl;
    return 0;
}
