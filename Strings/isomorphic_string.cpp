#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;
    map<char, char> charMap;
    map<char, bool> alreadyMapped;
    for (int i = 0; i < s.size(); i++)
    {
        if (charMap.find(t[i]) == charMap.end())
        {
            if (alreadyMapped.find(s[i]) == alreadyMapped.end())
            {
                charMap[t[i]] = s[i];
                alreadyMapped[s[i]] = t[i];
            }
            else
            {
                return false;
            }
        }
        if (s[i] != charMap[t[i]])
            return false;
    }
    return true;
}

int main()
{
    string s1 = "paper";
    string s2 = "title";
    cout << (isIsomorphic(s1, s2) ? "true" : "false") << endl;
    return 0;
}

// https://leetcode.com/problems/isomorphic-strings/