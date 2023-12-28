#include<bits/stdc++.h>
using namespace std;

uint32_t rotr(uint32_t n, unsigned int d) {
    return (n >> d)|(n << (32 - d));
}

uint32_t reverseBits(uint32_t n) {
	return rotr(n,32);
}

int main(){
    uint32_t n;
    cin>>n;
    cout<<reverseBits(n);
    return 0;
}