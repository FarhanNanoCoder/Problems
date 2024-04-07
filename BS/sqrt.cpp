#include<bits/stdc++.h>
using namespace std;

int sqrtBS(int n){
    int l=1;
    int r=n;
    int ans=1;
    while(l<=r){
        int m= (l+r)/2;
        if(m*m <=n){
            l= m+1;
            ans=m;
        }else{
            r=m-1;
        }
    }
    return ans;
}

int main(){
    cout<<sqrtBS(25)<<endl;
}