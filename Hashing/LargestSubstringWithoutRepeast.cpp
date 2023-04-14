#include <bits/stdc++.h>
using namespace std;

void printMap(map<char, int> m)
{
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
}
int lengthOfLongestSubstring(string s)
{
    map<char, int> stack;
    int length = 0;
    int l = 0, r = 0;
    while (r < s.length() && l < s.length())
    {
        if (stack.find(s[r]) != stack.end())
        {
            l = max(stack[s[r]] + 1,l);
            stack[s[r]] = r;
        }
        else
        {
            stack.insert({s[r], r});
        }

        r++;
        printMap(stack);
        cout<<l<<" "<<r<<endl;
        length = max(r - l, length);
    }
    return length;
}
int main()
{
    string s = "abba";
    cout << lengthOfLongestSubstring(s);
}