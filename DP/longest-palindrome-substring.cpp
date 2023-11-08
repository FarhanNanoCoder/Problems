#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    string res="";
    int l,r;
    for(int i=0;i<s.size();i++){

        l=i;
        r=i;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            if(res.size()< (r-l+1)){
                res = s.substr(l,r-l+1);
            }
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            if(res.size()< (r-l+1)){
                res = s.substr(l,r-l+1);
            }
            l--;
            r++;
        }
    }
    return res;
}
int main()
{
    string s="cbddb";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}

// https://leetcode.com/problems/longest-palindromic-substring/