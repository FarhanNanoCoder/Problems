#include <bits/stdc++.h>
using namespace std;
string rotateStr(string str)
{
    char l = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        str[i - 1] = str[i];
    }
    str[str.size() - 1] = l;
    return str;
}
bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        goal = rotateStr(goal);
        if (s == goal)
            return true;
    }
    return false;
}

int main()
{
    string s = "abcde";
    string goal = "edcba";
    if (rotateString(s, goal))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

// https://leetcode.com/problems/rotate-string/