#include <bits/stdc++.h>
using namespace std;

void printVector(vector<long long int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}


int segmentCount(unsigned long long int n,vector<pair<int,int>> ranges){
    sort(ranges.begin(),ranges.end());
    vector<long long int> limits;
    limits.push_back(ranges[0].first-1);
    long long int l= ranges[0].second;
    for(int i=1;i<ranges.size();i++){
        limits.push_back(ranges[i].first-l-1);
        l=ranges[i].second;
    }
    if(l!=n) limits.push_back(n-l);

    // printVector(limits);
    int c=0;
    for(int i=0;i<limits.size();i++){
        while(limits[i]){
            c+=limits[i]&1;
            limits[i]=limits[i]>>1;
        }
    }

    return c;
    
}

int main(){
    unsigned long long int n=14;
    vector<pair<int,int>> ranges={{5,5},{7,14}};
    cout<<segmentCount(n,ranges)<<endl;
    return 0;
}

