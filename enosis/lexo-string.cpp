#include<bits/stdc++.h>
using namespace std;

int charDistance(char a,char b){
    int diff = abs(a-b);
    return min(diff, 26-diff);
}

string lexicographicallySmallest(string s, int k){
    for(int i=0;i<s.size();i++){
        char smallest = 'z';
        for(char c='a';c<='z';c++){
            int distance = charDistance(s[i],c);
            if(distance<=k && c<smallest){
                smallest = c;
                break;
            }
        }
        k-=charDistance(s[i],smallest);
        s[i]=smallest;
    }
    return s;
}

int main(){
    string s1 = "abc";
    int k1 = 2;
    cout<<lexicographicallySmallest(s1,k1)<<endl;

    // string s2 = "zabc";
    // int k2 = 4;
    // cout<<lexicographicallySmallest(s2,k2)<<endl;
    string s2 = "adytc";
    int k2 = 5;
    cout<<lexicographicallySmallest(s2,k2)<<endl;
    return 0;
}