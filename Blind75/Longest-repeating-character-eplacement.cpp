#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    int l = 0, r = 0;
    map<char, int> freq;
    int maxFreq = 0;
    int res = 0;
    while ( r < s.size())
    {
        freq[s[r]]++;
        maxFreq = max(maxFreq, freq[s[r]]);
        if (r - l + 1 - maxFreq > k)
        {
            freq[s[l]]--;
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k);
}
// https://leetcode.com/problems/longest-repeating-character-replacement/description/