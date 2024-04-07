#include<bits/stdc+.h>
using namespace std;
    int calHours(vector<int> & piles,long long int h){
        int c=0;
        for(int i=0;i<piles.size();i++){
            
               c+= piles[i]/h + (piles[i]%h!=0);
        }
        return c;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=piles[0];
        int l=1;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>r) r=piles[i];
        }
        
        int ans=r;
        while(l<=r){
            int m = (l+r)/2;
            if(calHours(piles,m)>h){
                l=m+1;
                ans = min(ans,m);
            }else{
                r=m-1;
            }
                
        }
        return r;
    }

int main(){
    cout<<minEatingSpeed({3,6,7,11},8);
}