#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    map<char, int> target, window;

    for (int i = 0; i < t.size(); i++)
    {
        target[t[i]]++;
    }
    int have = 0, need = target.size();
    int start = 0, end = 0, len = 999999999, l = 0;
    for (int r = 0; r < s.size(); r++)
    {
        if (target[s[r]] != 0)
        {
            // cout<<s[r]<<endl;
            window[s[r]]++;
            if (window[s[r]] == target[s[r]])
                have++;
            if (have == need)
            {

                while (target[s[l]] == 0 || window[s[l]] > target[s[l]])
                {
                    if(window[s[l]]>0 && window[s[l]] > target[s[l]])
                        window[s[l]]--;  
                    l++;
                }

                // cout << l << " " << r << endl;
                if ((r - l + 1) < len)
                {
                    start = l;
                    end = r;
                    len = r - l + 1;
                    // cout<<start<<" "<<end<<" "<<len<<endl;
                }
                window[s[l]]--;
                l++;
                have--;
            }
        }
    }
    // cout<<start<<" "<<end<<" "<<len<<endl;
    if (len == 999999999)
        return "";
    return s.substr(start,len);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "A";
    cout<<minWindow(s, t);
}

// https://www.leetcode.com/problems/minimum-window-substring/