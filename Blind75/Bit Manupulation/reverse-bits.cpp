#include<bits/stdc++.h>
using namespace std;

// uint32_t rotr(uint32_t n, unsigned int d) {
//     return (n >> d)|(n << (32 - d));
// }

// uint32_t reverseBits(uint32_t n) {
// 	return rotr(n,32);
// }


uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for(int i=0;i<32;i++){
        res = res<<1;
        res = res | (n&1);
        n = n>>1;
    }
    return res;
}


int main(){
    uint32_t n;
    cin>>n;
    cout<<reverseBits(n);
    return 0;
}

//https://leetcode.com/problems/reverse-bits/