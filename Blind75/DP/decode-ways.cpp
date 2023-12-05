#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    if(s[0]=='0') return 0;

    int prev1=1; //i-1
    int prev2=1; // i-2
    int t=0,ones,tens;

    for(int i=1;i<s.size();i++){
        t=0;
        ones = stoi(s.substr(i,1));
        if(ones>=1 && ones<=9) t+=prev1;
        tens = stoi(s.substr(i-1,2));
        if(tens>=10 && tens<=26) t+=prev2;
        prev2 = prev1;
        prev1 = t;

        // cout<<"prev1: "<<prev1<<" prev2: "<<prev2<<endl;
    }

    return prev1;

}
int main()
{
    string s="11106";
    cout<<numDecodings(s)<<endl;
    return 0;

}