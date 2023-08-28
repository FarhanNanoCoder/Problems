#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> t;
    for (int i = 0; i < s.size(); i++)
    {

        if (!t.empty() )
        {
            if (s[i] == ')' && t.top() == '(')
            {
                t.pop();
            }
            else if (s[i] == '}' && t.top() == '{')
            {
                t.pop();
            }
            else if (s[i] == ']' && t.top() == '[')
            {
                t.pop();
            }
            else
            {
                t.push(s[i]);
            }
        }
        else
        {
            t.push(s[i]);
        }
    }
    return t.empty();
}

int main()
{
    string s = "()[]{}";
    cout << isValid(s);
}

// https://leetcode.com/problems/valid-parentheses/