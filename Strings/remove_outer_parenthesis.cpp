#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    string res = "";
    string temp = "";
    bool isFetching = false;
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (!isFetching && s[i] == '(')
        {
            isFetching = true;
            flag = 1;
            temp = "";
        }
        else if (isFetching)
        {
            if (s[i] == '(')
            {
                flag++;
                temp += s[i];
            }
            else
            {
                if (flag == 1)
                {
                    res += temp;
                    temp = "";
                    flag = 0;
                    isFetching = false;
                }
                else
                {
                    flag--;
                    temp += s[i];
                }
            }
        }
    }

    return res;
}

int main()
{
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl; // Output: "()()()"
    return 0;
}

// https://leetcode.com/problems/remove-outermost-parentheses/